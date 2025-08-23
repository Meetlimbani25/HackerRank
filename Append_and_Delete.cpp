#include <bits/stdc++.h>
using namespace std;

string appendAndDelete(string s, string t, int k) {
    int common = 0;
    int n = s.size(), m = t.size();
    
    // Find longest common prefix
    while (common < n && common < m && s[common] == t[common]) {
        common++;
    }
    
    int minOps = (n - common) + (m - common);
    
    if (k < minOps) {
        return "No";
    }
    else if (k >= n + m) {
        return "Yes";
    }
    else if ((k - minOps) % 2 == 0) {
        return "Yes";
    }
    else {
        return "No";
    }
}

int main() {
    string s, t;
    int k;
    cin >> s >> t >> k;
    cout << appendAndDelete(s, t, k) << endl;
    return 0;
}
