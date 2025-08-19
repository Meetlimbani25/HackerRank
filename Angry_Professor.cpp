#include <bits/stdc++.h>
using namespace std;

string angryProfessor(int k, vector<int> a) {
    int onTime = 0;
    for (int time : a) {
        if (time <= 0) {
            onTime++;
        }
    }
    return (onTime < k) ? "YES" : "NO";
}

int main() {
    int t;
    cin >> t;   // number of test cases
    while (t--) {
        int n, k;
        cin >> n >> k;     // number of students, threshold
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << angryProfessor(k, a) << endl;
    }
    return 0;
}
