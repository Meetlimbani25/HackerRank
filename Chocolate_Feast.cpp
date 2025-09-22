#include <bits/stdc++.h>
using namespace std;

int chocolateFeast(int n, int c, int m) {
    int chocolates = n / c;   // initial chocolates
    int wrappers = chocolates;

    while (wrappers >= m) {
        int newChocs = wrappers / m;   // trade wrappers for new chocolates
        chocolates += newChocs;
        wrappers = (wrappers % m) + newChocs;  // leftover + new wrappers
    }

    return chocolates;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c, m;
        cin >> n >> c >> m;
        cout << chocolateFeast(n, c, m) << endl;
    }
    return 0;
}
