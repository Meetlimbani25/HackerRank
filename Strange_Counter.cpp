#include <bits/stdc++.h>
using namespace std;

long strangeCounter(long t) {
    long cycleLength = 3;
    long cycleStart = 1;

    // Find the cycle where time t falls
    while (t > cycleStart + cycleLength - 1) {
        cycleStart += cycleLength;
        cycleLength *= 2;
    }

    // Remaining value at time t
    return cycleLength - (t - cycleStart);
}

int main() {
    long t;
    cin >> t;
    cout << strangeCounter(t) << endl;
    return 0;
}
