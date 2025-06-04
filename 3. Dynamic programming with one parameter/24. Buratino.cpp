#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n;
    char colon;
    cin >> n;
    vector <int> time(n + 1, 0), velocity(n);
    vector <int> ans(18 * 3600 + 1, 0);
    for (int i = 0, h, m, s, t; i < n; ++i) {
        cin >> h >> colon >> m >> colon >> s >> t;
        time.at(i) = h * 3600 + m * 60 + s;
        velocity.at(i) = t;
    }

    for (int i = 9 * 3600, v = 0, ii = -1; i < 18 * 3600; ++i) {
        if (time.at(ii + 1) == i)
            ++ii;

        ans.at(i + 1) = max(ans.at(i), ans.at(i + 1));

        if (i + velocity.at(ii) <= 13 * 3600 || i >= 14 * 3600 && i + velocity.at(ii) <= 18 * 3600)
            ans.at(i + velocity.at(ii)) = max(ans.at(i) + 1, ans.at(i + 1));
    }

    cout << ans.at(18 * 3600) << endl;

    return 0;
}
