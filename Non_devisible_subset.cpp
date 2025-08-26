#include <bits/stdc++.h>
using namespace std;

int nonDivisibleSubset(int k, vector<int> S) {
    vector<int> freq(k, 0);

    // Count frequencies of remainders when divided by k
    for (int num : S) {
        freq[num % k]++;
    }

    // At most one element with remainder 0 can be chosen
    int result = min(freq[0], 1);

    // For remainders i and k-i, pick the larger group
    for (int i = 1; i <= k / 2; i++) {
        if (i == k - i) {
            // Special case: when k is even, we can take only one element from remainder k/2
            result += 1;
        } else {
            result += max(freq[i], freq[k - i]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    cout << nonDivisibleSubset(k, S) << endl;

    return 0;
}
