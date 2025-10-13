#include <bits/stdc++.h>
using namespace std;

vector<string> detonate(vector<string> grid) {
    int r = grid.size(), c = grid[0].size();
    vector<string> result(r, string(c, 'O'));

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'O') {
                result[i][j] = '.';
                for (int k = 0; k < 4; k++) {
                    int ni = i + dr[k], nj = j + dc[k];
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c)
                        result[ni][nj] = '.';
                }
            }
        }
    }
    return result;
}

vector<string> bomberMan(int n, vector<string> grid) {
    if (n == 1) return grid;

    int r = grid.size(), c = grid[0].size();

    vector<string> full(r, string(c, 'O'));
    if (n % 2 == 0) return full;

    vector<string> after3 = detonate(grid);
    if (n % 4 == 3) return after3;

    vector<string> after5 = detonate(after3);
    return after5;
}

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) cin >> grid[i];

    vector<string> result = bomberMan(n, grid);
    for (auto &row : result)
        cout << row << "\n";

    return 0;
}
