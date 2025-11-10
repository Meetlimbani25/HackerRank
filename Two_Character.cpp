#include <bits/stdc++.h>
using namespace std;

// Helper to check if string alternates properly
bool isAlternating(const string &s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

int alternate(string s) {
    set<char> chars(s.begin(), s.end());
    vector<char> unique(chars.begin(), chars.end());
    int maxLen = 0;

    // Try all combinations of two unique characters
    for (int i = 0; i < unique.size(); i++) {
        for (int j = i + 1; j < unique.size(); j++) {
            string filtered;
            for (char c : s) {
                if (c == unique[i] || c == unique[j])
                    filtered += c;
            }

            if (isAlternating(filtered)) {
                maxLen = max(maxLen, (int)filtered.size());
            }
        }
    }

    return maxLen;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << alternate(s) << endl;
    return 0;
}
