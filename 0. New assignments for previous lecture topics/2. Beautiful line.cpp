#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int k;
    string s;
    vector <int> num(26, 0);
    cin >> k >> s;
    int l = 0, r = -1, maxch = 0, ans = 0;
    while (r < static_cast<int>(s.length() - 1)) {
        while (r < static_cast<int>(s.length() - 1)) {
            ++r;
            ++num.at(static_cast<int>(s.at(r) - 'a'));
            maxch = max(num.at(static_cast<int>(s.at(r) - 'a')), maxch);
            if (r - l + 1 - maxch <= k)
                ans = max(r - l + 1, ans);
            else
                break;
        }
        while (l < r) {
            --num.at(static_cast<int>(s.at(l) - 'a'));
            if (num.at(static_cast<int>(s.at(l) - 'a')) + 1 == maxch)
                maxch = *max_element(num.begin(), num.end());
            ++l;
            if (r - l + 1 - maxch <= k)
                break;
        }
    }

    cout << ans << endl;

    return 0;
}
