#include <bits/stdc++.h>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Maximum distance in each direction (without obstacles)
    int up = n - r_q;
    int down = r_q - 1;
    int right = n - c_q;
    int left = c_q - 1;
    int upRight = min(up, right);
    int upLeft = min(up, left);
    int downRight = min(down, right);
    int downLeft = min(down, left);

    // Put obstacles in a set for O(1) lookup
    set<pair<int,int>> obs;
    for (auto &o : obstacles) {
        obs.insert({o[0], o[1]});
    }

    // Reduce limits based on obstacles
    for (auto &o : obstacles) {
        int r = o[0], c = o[1];

        // Same column (up or down)
        if (c == c_q) {
            if (r > r_q) up = min(up, r - r_q - 1);
            else down = min(down, r_q - r - 1);
        }
        // Same row (left or right)
        else if (r == r_q) {
            if (c > c_q) right = min(right, c - c_q - 1);
            else left = min(left, c_q - c - 1);
        }
        // Diagonals
        else if (abs(r - r_q) == abs(c - c_q)) {
            if (r > r_q && c > c_q) upRight = min(upRight, r - r_q - 1);
            else if (r > r_q && c < c_q) upLeft = min(upLeft, r - r_q - 1);
            else if (r < r_q && c > c_q) downRight = min(downRight, c - c_q - 1);
            else if (r < r_q && c < c_q) downLeft = min(downLeft, r_q - r - 1);
        }
    }

    // Total attackable squares
    return up + down + left + right + upRight + upLeft + downRight + downLeft;
}

int main() {
    int n, k;
    cin >> n >> k;
    int r_q, c_q;
    cin >> r_q >> c_q;

    vector<vector<int>> obstacles(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> obstacles[i][0] >> obstacles[i][1];
    }

    cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;
    return 0;
}
