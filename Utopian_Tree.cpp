#include <bits/stdc++.h>
using namespace std;

int utopianTree(int n) {
    int height = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            height *= 2;   // spring
        } else {
            height += 1;   // summer
        }
    }
    return height;
}

int main() {
    int t; 
    cin >> t;   // number of test cases
    while (t--) {
        int n;
        cin >> n;
        cout << utopianTree(n) << endl;
    }
    return 0;
}
