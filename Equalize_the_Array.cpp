#include <bits/stdc++.h>
using namespace std;

int equalizeArray(vector<int> arr) {
    unordered_map<int,int> freq;
    
    for (int num : arr) {
        freq[num]++;
    }
    
    int maxFreq = 0;
    for (auto &p : freq) {
        maxFreq = max(maxFreq, p.second);
    }
    
    return arr.size() - maxFreq;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << equalizeArray(arr) << endl;
    return 0;
}
