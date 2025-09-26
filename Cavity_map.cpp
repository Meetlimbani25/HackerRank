#include <bits/stdc++.h>
using namespace std;

vector<string> cavityMap(vector<string> grid) {
    int n = grid.size();
    vector<string> result = grid; // copy to modify

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            char curr = grid[i][j];
            if (curr > grid[i-1][j] && curr > grid[i+1][j] &&
                curr > grid[i][j-1] && curr > grid[i][j+1]) {
                result[i][j] = 'X';
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<string> ans = cavityMap(grid);
    for (string row : ans) {
        cout << row << "\n";
    }
    return 0;
}
