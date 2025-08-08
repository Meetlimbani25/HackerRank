#include <iostream>
using namespace std;

int pageCount(int n, int p) {
    // From front: each page turn covers 2 pages (left and right)
    int fromFront = p / 2;

    // From back: depends on whether n is even or odd
    int fromBack = (n / 2) - (p / 2);

    return min(fromFront, fromBack);
}

int main() {
    int n, p;
    cin >> n >> p;

    cout << pageCount(n, p) << endl;

    return 0;
}
