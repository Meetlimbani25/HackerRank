#include <bits/stdc++.h>
using namespace std;

string catAndMouse(int x, int y, int z) {
    int distA = abs(z - x); // Distance from Cat A to mouse
    int distB = abs(z - y); // Distance from Cat B to mouse

    if (distA < distB) return "Cat A";
    else if (distB < distA) return "Cat B";
    else return "Mouse C";
}

int main() {
    int q; 
    cin >> q;

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << catAndMouse(x, y, z) << endl;
    }

    return 0;
}
