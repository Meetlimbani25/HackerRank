#include <bits/stdc++.h>
using namespace std;

vector<int> acmTeam(vector<string> topic) {
    int n = topic.size();
    int m = topic[0].size();
    int maxTopics = 0;
    int teamCount = 0;

    // Compare every pair of attendees
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int known = 0;
            for (int k = 0; k < m; k++) {
                if (topic[i][k] == '1' || topic[j][k] == '1') {
                    known++;
                }
            }
            if (known > maxTopics) {
                maxTopics = known;
                teamCount = 1;   // reset count
            } else if (known == maxTopics) {
                teamCount++;
            }
        }
    }

    return {maxTopics, teamCount};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> topic(n);
    for (int i = 0; i < n; i++) {
        cin >> topic[i];
    }

    vector<int> result = acmTeam(topic);
    cout << result[0] << "\n" << result[1] << endl;
    return 0;
}
