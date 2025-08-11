#include <bits/stdc++.h>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    int maxSpent = -1; // Default to -1 if no valid combination

    for (int k : keyboards) {
        for (int d : drives) {
            int total = k + d;
            if (total <= b && total > maxSpent) {
                maxSpent = total;
            }
        }
    }
    return maxSpent;
}

int main() {
    int b, n, m;
    cin >> b >> n >> m;

    vector<int> keyboards(n), drives(m);

    for (int i = 0; i < n; i++) cin >> keyboards[i];
    for (int i = 0; i < m; i++) cin >> drives[i];

    cout << getMoneySpent(keyboards, drives, b) << endl;
    return 0;
}
