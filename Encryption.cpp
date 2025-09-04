#include <bits/stdc++.h>
using namespace std;

string encryption(string s) {
    // Step 1: Remove spaces
    string clean = "";
    for (char c : s) {
        if (c != ' ') clean += c;
    }
    int L = clean.size();

    // Step 2: Find rows and cols
    int rows = floor(sqrt(L));
    int cols = ceil(sqrt(L));
    if (rows * cols < L) rows++;

    // Step 3: Read column by column
    string result = "";
    for (int c = 0; c < cols; c++) {
        if (c > 0) result += " ";  // space between columns
        for (int r = 0; r < rows; r++) {
            int idx = r * cols + c;
            if (idx < L) result += clean[idx];
        }
    }
    return result;
}

int main() {
    string s;
    getline(cin, s);
    cout << encryption(s) << "\n";
    return 0;
}
