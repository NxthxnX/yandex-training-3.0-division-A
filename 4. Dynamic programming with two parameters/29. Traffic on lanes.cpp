#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector <vector <long long> > dp(m + 1, vector <long long>(n + 1, 0));
    dp.at(1).at(1) = 1;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp.at(i).at(j) += dp.at(i - 1).at(j - 1) + dp.at(i - 1).at(j) + dp.at(i).at(j - 1);

    cout << dp.at(m).at(n) << endl;

    return 0;
}
