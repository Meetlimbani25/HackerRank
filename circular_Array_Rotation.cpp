#include <bits/stdc++.h>
using namespace std;

vector<int> circularArrayRotation(vector<int>& a, int k, vector<int>& queries) {
    int n = a.size();
    vector<int> result;
    k = k % n; // reduce unnecessary rotations

    for (int q : queries) {
        int originalIndex = (q - k + n) % n;
        result.push_back(a[originalIndex]);
    }
    return result;
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    vector<int> ans = circularArrayRotation(a, k, queries);
    for (int val : ans) {
        cout << val << endl;
    }

    return 0;
}
