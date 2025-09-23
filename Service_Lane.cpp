#include <bits/stdc++.h>
using namespace std;

vector<int> serviceLane(int n, vector<vector<int>> cases, vector<int> width) {
    vector<int> result;
    for (auto query : cases) {
        int start = query[0], end = query[1];
        int minWidth = INT_MAX;
        for (int k = start; k <= end; k++) {
            minWidth = min(minWidth, width[k]);
        }
        result.push_back(minWidth);
    }
    return result;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> width(n);
    for (int i = 0; i < n; i++) {
        cin >> width[i];
    }

    vector<vector<int>> cases(t, vector<int>(2));
    for (int i = 0; i < t; i++) {
        cin >> cases[i][0] >> cases[i][1];
    }

    vector<int> ans = serviceLane(n, cases, width);

    for (int res : ans) {
        cout << res << endl;
    }
    return 0;
}
