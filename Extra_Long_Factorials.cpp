#include <bits/stdc++.h>
using namespace std;

// Function to multiply a big number stored in vector with an integer
void multiply(vector<int> &res, int x) {
    int carry = 0;

    for (int i = 0; i < res.size(); i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry) {
        res.push_back(carry % 10);
        carry /= 10;
    }
}

// Function to compute factorial
void extraLongFactorials(int n) {
    vector<int> res;
    res.push_back(1); // factorial starts with 1

    for (int i = 2; i <= n; i++) {
        multiply(res, i);
    }

    // Print in reverse (since digits are stored in reverse order)
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}
