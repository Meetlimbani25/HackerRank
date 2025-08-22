#include <bits/stdc++.h>
using namespace std;

int findDigits(int n) {
    int count = 0;
    int temp = n;
    
    while (temp > 0) {
        int digit = temp % 10;  // extract last digit
        if (digit != 0 && n % digit == 0) {
            count++;
        }
        temp /= 10;  // remove last digit
    }
    return count;
}

int main() {
    int t;
    cin >> t;  // number of test cases
    while (t--) {
        int n;
        cin >> n;
        cout << findDigits(n) << endl;
    }
    return 0;
}
