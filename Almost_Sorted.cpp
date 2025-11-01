#include <bits/stdc++.h>
using namespace std;

void almostSorted(vector<int> arr) {
    int n = arr.size();
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    // find indices where arr != sorted
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        if (arr[i] != sorted[i])
            diff.push_back(i);
    }

    // already sorted
    if (diff.empty()) {
        cout << "yes" << endl;
        return;
    }

    int l = diff.front();
    int r = diff.back();

    // Try swap
    swap(arr[l], arr[r]);
    if (arr == sorted) {
        cout << "yes" << endl;
        cout << "swap " << l + 1 << " " << r + 1 << endl;
        return;
    }

    // Undo swap and try reverse
    swap(arr[l], arr[r]);
    reverse(arr.begin() + l, arr.begin() + r + 1);
    if (arr == sorted) {
        cout << "yes" << endl;
        cout << "reverse " << l + 1 << " " << r + 1 << endl;
        return;
    }

    // If neither works
    cout << "no" << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    almostSorted(arr);
    return 0;
}
