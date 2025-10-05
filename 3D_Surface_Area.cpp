#include <bits/stdc++.h>
using namespace std;

int surfaceArea(vector<vector<int>> A) {
    int n = A.size();
    int m = A[0].size();
    int area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] > 0) {
                // top and bottom
                area += 2;

                // north
                area += max(0, A[i][j] - (i > 0 ? A[i-1][j] : 0));
                // south
                area += max(0, A[i][j] - (i < n-1 ? A[i+1][j] : 0));
                // west
                area += max(0, A[i][j] - (j > 0 ? A[i][j-1] : 0));
                // east
                area += max(0, A[i][j] - (j < m-1 ? A[i][j+1] : 0));
            }
        }
    }

    return area;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    cout << surfaceArea(grid) << endl;
    return 0;
}
