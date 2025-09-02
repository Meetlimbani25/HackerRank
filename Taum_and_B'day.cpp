#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long b, w;
        long long bc, wc, z;
        cin >> b >> w;
        cin >> bc >> wc >> z;

        long long costBlack = min(bc, wc + z);
        long long costWhite = min(wc, bc + z);

        long long total = b * costBlack + w * costWhite;
        cout << total << "\n";
    }
    return 0;
}
