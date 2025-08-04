#include <iostream>
#include <vector>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int appleCount = 0, orangeCount = 0;

    // Check each apple
    for (int i = 0; i < apples.size(); i++) {
        int landingPosition = a + apples[i];
        if (landingPosition >= s && landingPosition <= t) {
            appleCount++;
        }
    }

    // Check each orange
    for (int i = 0; i < oranges.size(); i++) {
        int landingPosition = b + oranges[i];
        if (landingPosition >= s && landingPosition <= t) {
            orangeCount++;
        }
    }

    cout << appleCount << endl;
    cout << orangeCount << endl;
}

int main() {
    int s, t, a, b, m, n;

    // Read house range
    cin >> s >> t;

    // Read tree positions
    cin >> a >> b;

    // Read number of apples and oranges
    cin >> m >> n;

    vector<int> apples(m), oranges(n);

    for (int i = 0; i < m; i++) {
        cin >> apples[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> oranges[i];
    }

    // Call the function
    countApplesAndOranges(s, t, a, b, apples, oranges);

    return 0;
}
