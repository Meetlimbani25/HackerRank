#include <bits/stdc++.h>
using namespace std;

int hurdleRace(int k, vector<int> height) {
    int maxHeight = *max_element(height.begin(), height.end());
    return max(0, maxHeight - k);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << hurdleRace(k, height) << endl;
    return 0;
}
