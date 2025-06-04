#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <limits>

using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector <vector <int> > field(n + 2, vector <int>(m + 2, numeric_limits<int>::max()));
    vector <vector <bool> > been(n + 2, vector <bool>(m + 2, false));
    array <int, 4> di{ -1, 0, 1, 0 }, dj{ 0, 1, 0, -1 };
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> field.at(i).at(j);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (been.at(i).at(j))
                continue;

            bool havelower = false;

            stack <pair <int, int> > same;
            same.push(make_pair(i, j));
            while (same.size()) {
                auto [x, y] = same.top();
                same.pop();
                if (been.at(x).at(y))
                    continue;

                for (int k = 0; k < 4; ++k) {
                    if (field.at(x + di.at(k)).at(y + dj.at(k)) == field.at(x).at(y))
                        same.push(make_pair(x + di.at(k), y + dj.at(k)));
                    if (field.at(x + di.at(k)).at(y + dj.at(k)) < field.at(x).at(y))
                        havelower = true;
                }

                been.at(x).at(y) = true;
            }

            if (!havelower)
                ++ans;
        }

    cout << ans << endl;

    return 0;
}
