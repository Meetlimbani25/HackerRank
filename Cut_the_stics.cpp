#include <bits/stdc++.h>
using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
    sort(arr.begin(), arr.end());
    vector<int> result;
    
    int n = arr.size();
    result.push_back(n); // first iteration has all sticks
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) {
            result.push_back(n - i);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> res = cutTheSticks(arr);
    for (int x : res) cout << x << "\n";
    return 0;
}
