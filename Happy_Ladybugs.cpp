#include <bits/stdc++.h>
using namespace std;

string happyLadybugs(string b) {
    unordered_map<char, int> freq;
    int n = b.size();
    bool hasEmpty = false;

    // Count frequencies, check if '_' exists
    for (char c : b) {
        if (c == '_') {
            hasEmpty = true;
        } else {
            freq[c]++;
        }
    }

    // Case 1: No empty cell -> must already be happy
    if (!hasEmpty) {
        for (int i = 0; i < n; i++) {
            if (!((i > 0 && b[i] == b[i-1]) || (i < n-1 && b[i] == b[i+1]))) {
                return "NO";
            }
        }
        return "YES";
    }

    // Case 2: There are empty cells -> check frequencies
    for (auto &p : freq) {
        if (p.second == 1) {
            return "NO"; // single ladybug cannot be paired
        }
    }

    return "YES";
}

int main() {
    int g; 
    cin >> g;  // number of games
    while (g--) {
        int n;
        cin >> n;
        string b;
        cin >> b;
        cout << happyLadybugs(b) << "\n";
    }
    return 0;
}
