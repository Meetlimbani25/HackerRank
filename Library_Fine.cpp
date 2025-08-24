#include <bits/stdc++.h>
using namespace std;

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    // Case 1: Returned before or on due date
    if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 <= d2)) {
        return 0;
    }

    // Case 2: Returned late but same year and month
    if (y1 == y2 && m1 == m2 && d1 > d2) {
        return 15 * (d1 - d2);
    }

    // Case 3: Returned late but same year
    if (y1 == y2 && m1 > m2) {
        return 500 * (m1 - m2);
    }

    // Case 4: Returned in later year
    if (y1 > y2) {
        return 10000;
    }

    return 0; // Default (should never hit here)
}

int main() {
    int d1, m1, y1;
    int d2, m2, y2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;

    cout << libraryFine(d1, m1, y1, d2, m2, y2) << endl;
    return 0;
}
