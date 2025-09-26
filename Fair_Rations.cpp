#include <bits/stdc++.h>
using namespace std;

string fairRations(vector<int> B) {
    int n = B.size();
    int totalLoaves = 0;

    // Count how many odd numbers exist
    int oddCount = 0;
    for (int x : B) {
        if (x % 2 != 0) oddCount++;
    }

    if (oddCount % 2 != 0) {
        return "NO"; // impossible
    }

    for (int i = 0; i < n - 1; i++) {
        if (B[i] % 2 != 0) {
            // give one loaf to i and i+1
            B[i]++;
            B[i+1]++;
            totalLoaves += 2;
        }
    }

    return to_string(totalLoaves);
}

int main() {
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    cout << fairRations(B) << endl;
    return 0;
}
