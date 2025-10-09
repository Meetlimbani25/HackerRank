#include <bits/stdc++.h>
using namespace std;

string larrysArray(vector<int> A) {
    int n = A.size();
    long long inversions = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) inversions++;
        }
    }

    // If inversion count is even, possible
    return (inversions % 2 == 0) ? "YES" : "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << larrysArray(A) << endl;
    }
    return 0;
}
