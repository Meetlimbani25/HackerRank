#include <bits/stdc++.h>
using namespace std;

string timeInWords(int h, int m) {
    vector<string> nums = {"zero","one","two","three","four","five","six","seven","eight","nine","ten",
                           "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                           "eighteen","nineteen","twenty","twenty one","twenty two","twenty three",
                           "twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine"};

    if (m == 0) return nums[h] + " o' clock";
    else if (m == 15) return "quarter past " + nums[h];
    else if (m == 30) return "half past " + nums[h];
    else if (m == 45) return "quarter to " + nums[(h % 12) + 1];
    else if (m < 30) return nums[m] + " minute" + (m == 1 ? "" : "s") + " past " + nums[h];
    else {
        int mins = 60 - m;
        return nums[mins] + " minute" + (mins == 1 ? "" : "s") + " to " + nums[(h % 12) + 1];
    }
}

int main() {
    int h, m;
    cin >> h >> m;
    cout << timeInWords(h, m) << endl;
    return 0;
}
