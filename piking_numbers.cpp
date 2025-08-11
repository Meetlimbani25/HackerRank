#include <bits/stdc++.h>
using namespace std;

int pickingNumbers(vector<int> a) {
    vector<int> freq(101, 0); // values are between 0 and 100

    // Count frequency of each number
    for (int num : a) {
        freq[num]++;
    }

    int maxLen = 0;
    for (int i = 1; i <= 100; i++) {
        maxLen = max(maxLen, freq[i] + freq[i - 1]);
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << pickingNumbers(a) << endl;
    return 0;
}
