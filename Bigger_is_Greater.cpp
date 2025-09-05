#include <bits/stdc++.h>
using namespace std;

string biggerIsGreater(string w) {
    int n = w.size();
    
    // Step 1: Find pivot
    int i = n - 2;
    while (i >= 0 && w[i] >= w[i + 1]) {
        i--;
    }
    if (i < 0) {
        return "no answer";
    }

    // Step 2: Find successor
    int j = n - 1;
    while (w[j] <= w[i]) {
        j--;
    }

    // Step 3: Swap
    swap(w[i], w[j]);

    // Step 4: Reverse the suffix
    reverse(w.begin() + i + 1, w.end());

    return w;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string w;
        cin >> w;
        cout << biggerIsGreater(w) << "\n";
    }
    return 0;
}
