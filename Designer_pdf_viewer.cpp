#include <bits/stdc++.h>
using namespace std;

int designerPdfViewer(vector<int> h, string word) {
    int maxHeight = 0;

    for (char c : word) {
        int index = c - 'a';       // map char to 0-25
        maxHeight = max(maxHeight, h[index]);
    }

    return maxHeight * word.size();
}

int main() {
    vector<int> h(26);
    for (int i = 0; i < 26; i++) {
        cin >> h[i];
    }

    string word;
    cin >> word;

    cout << designerPdfViewer(h, word) << endl;
    return 0;
}
