#include <bits/stdc++.h>
using namespace std;

int saveThePrisoner(int n, int m, int s) {
    int last = (s + m - 1) % n;
    return (last == 0) ? n : last;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, s;
        cin >> n >> m >> s;
        cout << saveThePrisoner(n, m, s) << endl;
    }
    return 0;
}
