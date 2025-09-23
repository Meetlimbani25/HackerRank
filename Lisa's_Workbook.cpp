#include <bits/stdc++.h>
using namespace std;

int workbook(int n, int k, vector<int> arr) {
    int page = 1; // starting page
    int special = 0;

    for (int i = 0; i < n; i++) {
        int problems = arr[i];
        for (int problem = 1; problem <= problems; problem++) {
            // start of a new page
            if ((problem - 1) % k == 0 && problem != 1) {
                page++;
            }
            // check if special
            if (problem == page) {
                special++;
            }
        }
        page++; // move to next page after chapter ends
    }
    return special;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << workbook(n, k, arr) << endl;
    return 0;
}
