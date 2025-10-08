#include <bits/stdc++.h>
using namespace std;

// Helper structure to store a plus
struct Plus {
    int r, c, arm; // center row, center col, and arm length
    vector<pair<int,int>> cells; // list of covered cells

    int area() const {
        return 1 + 4 * arm;
    }
};

// Get all cells occupied by a plus
vector<pair<int,int>> getCells(int r, int c, int arm) {
    vector<pair<int,int>> cells = {{r, c}};
    for (int k = 1; k <= arm; k++) {
        cells.push_back({r + k, c});
        cells.push_back({r - k, c});
        cells.push_back({r, c + k});
        cells.push_back({r, c - k});
    }
    return cells;
}

bool overlap(const Plus &a, const Plus &b) {
    for (auto &ca : a.cells)
        for (auto &cb : b.cells)
            if (ca == cb)
                return true;
    return false;
}

int twoPluses(vector<string> grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<Plus> pluses;

    // Find all valid pluses
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'G') {
                int arm = 0;
                while (i - arm >= 0 && i + arm < n && j - arm >= 0 && j + arm < m &&
                       grid[i - arm][j] == 'G' && grid[i + arm][j] == 'G' &&
                       grid[i][j - arm] == 'G' && grid[i][j + arm] == 'G') {
                    Plus p;
                    p.r = i;
                    p.c = j;
                    p.arm = arm;
                    p.cells = getCells(i, j, arm);
                    pluses.push_back(p);
                    arm++;
                }
            }
        }
    }

    int maxProduct = 0;

    // Compare all pairs of pluses
    for (int i = 0; i < pluses.size(); i++) {
        for (int j = i + 1; j < pluses.size(); j++) {
            if (!overlap(pluses[i], pluses[j])) {
                int product = pluses[i].area() * pluses[j].area();
                maxProduct = max(maxProduct, product);
            }
        }
    }

    return maxProduct;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    cout << twoPluses(grid) << endl;
    return 0;
}
