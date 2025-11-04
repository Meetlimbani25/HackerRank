#include <bits/stdc++.h>
using namespace std;

void insertionSort1(int n, vector<int> arr) {
    int key = arr[n - 1]; // The element to insert
    int i = n - 2;

    // Shift elements greater than key to the right
    while (i >= 0 && arr[i] > key) {
        arr[i + 1] = arr[i];
        for (int j = 0; j < n; j++)
            cout << arr[j] << " ";
        cout << endl;
        i--;
    }

    // Insert key into correct position
    arr[i + 1] = key;
    for (int j = 0; j < n; j++)
        cout << arr[j] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort1(n, arr);
    return 0;
}
