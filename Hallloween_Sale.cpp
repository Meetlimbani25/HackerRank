#include <bits/stdc++.h>
using namespace std;

int howManyGames(int p, int d, int m, int s) {
    int count = 0;
    int price = p;

    while (s >= price) {
        s -= price;
        count++;
        price = max(price - d, m);
    }

    return count;
}

int main() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;
    cout << howManyGames(p, d, m, s) << endl;
    return 0;
}
