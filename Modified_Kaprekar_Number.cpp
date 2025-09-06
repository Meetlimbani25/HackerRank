#include <bits/stdc++.h>
using namespace std;

void kaprekarNumbers(int p, int q) {
    vector<int> result;

    for (long long n = p; n <= q; n++) {
        long long sq = n * 1LL * n;
        string s = to_string(sq);
        int d = to_string(n).size();

        // Right part (last d digits)
        string rightStr = (s.size() >= d) ? s.substr(s.size() - d) : s;
        // Left part (remaining digits or 0)
        string leftStr = (s.size() > d) ? s.substr(0, s.size() - d) : "0";

        long long leftNum = stoll(leftStr);
        long long rightNum = stoll(rightStr);

        if (leftNum + rightNum == n) {
            result.push_back(n);
        }
    }

    if (result.empty()) {
        cout << "INVALID RANGE";
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << (i + 1 < result.size() ? " " : "");
        }
    }
    cout << endl;
}

int main() {
    int p, q;
    cin >> p >> q;
    kaprekarNumbers(p, q);
    return 0;
}
