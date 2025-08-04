#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr) {
    // Since bird types range from 1 to 5, we use size 6 (index 0 is unused)
    vector<int> freq(6, 0);

    // Count frequency of each bird type
    for (int bird : arr) {
        freq[bird]++;
    }

    int maxFreq = 0;
    int birdType = 0;

    // Find the type with the highest frequency, and if tie, smallest ID
    for (int i = 1; i <= 5; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            birdType = i;
        }
    }

    return birdType;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = migratoryBirds(arr);
    cout << result << endl;

    return 0;
}
