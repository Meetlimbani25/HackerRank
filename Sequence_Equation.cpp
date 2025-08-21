#include <bits/stdc++.h>
using namespace std;

vector<int> permutationEquation(vector<int> p) {
    int n = p.size();
    vector<int> pos(n+1); // store positions of each number
    
    // Map value -> index
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i + 1;  // +1 because sequence is 1-indexed
    }
    
    vector<int> result;
    for (int x = 1; x <= n; x++) {
        int y = pos[pos[x]];
        result.push_back(y);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    
    vector<int> ans = permutationEquation(p);
    for (int val : ans) cout << val << "\n";
    
    return 0;
}
