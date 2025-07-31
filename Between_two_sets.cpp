#include <iostream>
#include <vector>
using namespace std;

// Function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Main function to find the number of integers between the sets
int getTotalX(vector<int> a, vector<int> b) {
    // Step 1: Find LCM of all elements in a
    int lcm_a = a[0];
    for (int i = 1; i < a.size(); i++) {
        lcm_a = lcm(lcm_a, a[i]);
    }

    // Step 2: Find GCD of all elements in b
    int gcd_b = b[0];
    for (int i = 1; i < b.size(); i++) {
        gcd_b = gcd(gcd_b, b[i]);
    }

    // Step 3: Count how many multiples of lcm_a divide gcd_b
    int count = 0;
    for (int i = lcm_a; i <= gcd_b; i += lcm_a) {
        if (gcd_b % i == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    cout << getTotalX(a, b) << endl;

    return 0;
}
