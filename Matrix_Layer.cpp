#include <bits/stdc++.h>
using namespace std;

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size();
    int n = matrix[0].size();
    int layers = min(m, n) / 2;

    for (int layer = 0; layer < layers; ++layer) {
        vector<int> elements;

        int top = layer;
        int bottom = m - layer - 1;
        int left = layer;
        int right = n - layer - 1;

        // extract the layer
        for (int i = left; i <= right; ++i) elements.push_back(matrix[top][i]); // top row
        for (int i = top + 1; i <= bottom - 1; ++i) elements.push_back(matrix[i][right]); // right col
        for (int i = right; i >= left; --i) elements.push_back(matrix[bottom][i]); // bottom row
        for (int i = bottom - 1; i >= top + 1; --i) elements.push_back(matrix[i][left]); // left col

        int len = elements.size();
        int rot = r % len;

        // rotated version
        vector<int> rotated(len);
        for (int i = 0; i < len; ++i)
            rotated[i] = elements[(i + rot) % len];

        int idx = 0;

        // put rotated elements back
        for (int i = left; i <= right; ++i) matrix[top][i] = rotated[idx++]; // top
        for (int i = top + 1; i <= bottom - 1; ++i) matrix[i][right] = rotated[idx++]; // right
        for (int i = right; i >= left; --i) matrix[bottom][i] = rotated[idx++]; // bottom
        for (int i = bottom - 1; i >= top + 1; --i) matrix[i][left] = rotated[idx++]; // left
    }

    // print final matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int m, n, r;
    cin >> m >> n >> r;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    matrixRotation(matrix, r);
    return 0;
}
