#include <bits/stdc++.h>
using namespace std;

string gridSearch(vector<string> G, vector<string> P) {
    int R = G.size();       // rows of grid
    int C = G[0].size();    // cols of grid
    int r = P.size();       // rows of pattern
    int c = P[0].size();    // cols of pattern

    for (int i = 0; i <= R - r; i++) {           // loop grid rows
        for (int j = 0; j <= C - c; j++) {       // loop grid cols
            bool found = true;
            for (int x = 0; x < r; x++) {        // check each row of pattern
                if (G[i + x].substr(j, c) != P[x]) {
                    found = false;
                    break;
                }
            }
            if (found) return "YES";
        }
    }
    return "NO";
}

int main() {
    int t;
    cin >> t;  // number of test cases
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<string> G(R);
        for (int i = 0; i < R; i++) cin >> G[i];

        int r, c;
        cin >> r >> c;
        vector<string> P(r);
        for (int i = 0; i < r; i++) cin >> P[i];

        cout << gridSearch(G, P) << "\n";
    }
    return 0;
}
