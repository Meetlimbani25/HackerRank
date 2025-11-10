#include <bits/stdc++.h>
using namespace std;

int marsExploration(string s) {
    int count = 0;
    string pattern = "SOS";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != pattern[i % 3]) {
            count++;
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s;
    cout << marsExploration(s) << endl;
    return 0;
}
