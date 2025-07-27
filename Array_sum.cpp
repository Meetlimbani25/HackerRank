#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the sum of array elements
int simpleArraySum(vector<int> ar) {
    int sum = 0;
    for (int i = 0; i < ar.size(); i++) {
        sum += ar[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n; // Read size of array

    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i]; // Read array elements
    }

    int result = simpleArraySum(ar);
    cout << result << endl; // Print the sum

    return 0;
}
