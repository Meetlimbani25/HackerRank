#include <bits/stdc++.h>
using namespace std;

int flatlandSpaceStations(int n, vector<int> c) {
    sort(c.begin(), c.end()); // sort stations
    
    int maxDist = 0;

    // Distance before the first station
    maxDist = max(maxDist, c[0] - 0);

    // Distance after the last station
    maxDist = max(maxDist, n - 1 - c.back());

    // Distance between stations
    for (size_t i = 0; i < c.size() - 1; i++) {
        int dist = (c[i+1] - c[i]) / 2; // max distance in between
        maxDist = max(maxDist, dist);
    }

    return maxDist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    cout << flatlandSpaceStations(n, c) << endl;
    return 0;
}
