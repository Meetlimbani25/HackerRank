#include <iostream>
using namespace std;

int countingValleys(int steps, string path) {
    int seaLevel = 0;
    int currentLevel = 0;
    int valleyCount = 0;

    for (char step : path) {
        if (step == 'U') {
            currentLevel++;
            // If we just came up to sea level, it's the end of a valley
            if (currentLevel == 0) {
                valleyCount++;
            }
        } else if (step == 'D') {
            currentLevel--;
        }
    }

    return valleyCount;
}

int main() {
    int steps;
    string path;
    cin >> steps >> path;

    cout << countingValleys(steps, path) << endl;

    return 0;
}
