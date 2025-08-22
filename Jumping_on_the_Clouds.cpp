#include <bits/stdc++.h>
using namespace std;

int jumpingOnClouds(vector<int> c, int k) {
    int n = c.size();
    int energy = 100;  // starting energy
    int pos = 0;       // starting at cloud 0
    
    do {
        // jump k steps ahead (circular using modulo)
        pos = (pos + k) % n;
        
        // use 1 energy for jump + 2 extra if thunderhead
        energy -= (1 + 2 * c[pos]);
        
    } while (pos != 0); // stop when back at starting cloud
    
    return energy;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    cout << jumpingOnClouds(c, k) << endl;
    return 0;
}
