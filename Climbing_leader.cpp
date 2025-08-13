#include <bits/stdc++.h>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    // Remove duplicates from ranked
    vector<int> uniqueRanked;
    uniqueRanked.push_back(ranked[0]);
    for (int i = 1; i < ranked.size(); i++) {
        if (ranked[i] != ranked[i - 1]) {
            uniqueRanked.push_back(ranked[i]);
        }
    }

    vector<int> result;
    int n = uniqueRanked.size();
    int index = n - 1; // start from the lowest ranked score

    // Iterate over player scores in ascending order
    for (int score : player) {
        // Move up the leaderboard while player's score is >= current ranked score
        while (index >= 0 && score >= uniqueRanked[index]) {
            index--;
        }
        // If index == -1, player is top rank, else rank is index + 2
        result.push_back(index + 2);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> ranked(n);
    for (int i = 0; i < n; i++) cin >> ranked[i];

    int m;
    cin >> m;
    vector<int> player(m);
    for (int i = 0; i < m; i++) cin >> player[i];

    vector<int> res = climbingLeaderboard(ranked, player);
    for (int r : res) cout << r << "\n";

    return 0;
}
