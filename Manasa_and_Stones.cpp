#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long n, a, b;
        cin >> n >> a >> b;
        if (a == b) {
            // Only one possible value
            cout << (n - 1) * a << "\n";
            continue;
        }
        // Ensure a < b so results come out sorted
        if (a > b) swap(a, b);
        
        // k = number of times we use b, ranges 0..n-1
        // last = (n-1-k)*a + k*b = (n-1)*a + k*(b-a)
        long long base = (n - 1) * a;
        long long diff = b - a;
        for (long long k = 0; k <= n - 1; ++k) {
            long long val = base + k * diff;
            if (k) cout << " ";
            cout << val;
        }
        cout << "\n";
    }
    return 0;
}
