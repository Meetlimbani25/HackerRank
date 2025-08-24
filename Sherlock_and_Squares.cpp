#include <bits/stdc++.h>
using namespace std;

int squares(int a, int b) {
    int start = ceil(sqrt(a));
    int end = floor(sqrt(b));
    int result = end - start + 1;
    return (result > 0) ? result : 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << squares(a, b) << endl;
    }
    return 0;
}
