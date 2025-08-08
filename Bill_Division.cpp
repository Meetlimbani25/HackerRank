#include <iostream>
#include <vector>
using namespace std;

void bonAppetit(const vector<int>& bill, int k, int b) {
    int total = 0;

    // Calculate the total excluding the item Anna didn't eat
    for (size_t i = 0; i < bill.size(); i++) {
        if (i != static_cast<size_t>(k)) {
            total += bill[i];
        }
    }

    int fair_share = total / 2;

    if (b == fair_share) {
        cout << "Bon Appetit" << endl;
    } else {
        cout << b - fair_share << endl;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> bill(n);
    for (int i = 0; i < n; i++) {
        cin >> bill[i];
    }

    int b;
    cin >> b;

    bonAppetit(bill, k, b);

    return 0;
}
