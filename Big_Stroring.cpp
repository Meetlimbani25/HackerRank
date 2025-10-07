#include <bits/stdc++.h>
using namespace std;

bool customSort(const string &a, const string &b) {
    // First compare by length
    if (a.size() != b.size())
        return a.size() < b.size();
    // If lengths are equal, compare lexicographically
    return a < b;
}

int main() {
    int n;
    cin >> n;
    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        cin >> unsorted[i];
    }

    sort(unsorted.begin(), unsorted.end(), customSort);

    for (const string &num : unsorted) {
        cout << num << "\n";
    }

    return 0;
}
