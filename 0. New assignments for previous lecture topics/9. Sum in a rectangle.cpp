#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int> > table(n + 1, vector <int>(m + 1, 0)), sum(n + 1, vector <int>(m + 1, 0));
    vector <int> ans(k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> table.at(i).at(j);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum.at(i).at(j) = table.at(i).at(j) + sum.at(i - 1).at(j) + sum.at(i).at(j - 1) - sum.at(i - 1).at(j - 1);

    for (int i = 0, x1, y1, x2, y2; i < k; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans.at(i) = sum.at(x2).at(y2) - sum.at(x1 - 1).at(y2) - sum.at(x2).at(y1 - 1) + sum.at(x1 - 1).at(y1 - 1);
    }

    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));

    return 0;
}
