#include <iostream>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    // If they have the same speed and different starting points, they will never meet
    if (v1 == v2) {
        return (x1 == x2) ? "YES" : "NO";
    }

    // Check if (x2 - x1) is divisible by (v1 - v2) and if the kangaroo with smaller start jumps farther
    if ((x2 - x1) % (v1 - v2) == 0 && ((x1 < x2 && v1 > v2) || (x1 > x2 && v1 < v2))) {
        return "YES";
    }

    return "NO";
}

int main() {
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    cout << kangaroo(x1, v1, x2, v2) << endl;
    return 0;
}
