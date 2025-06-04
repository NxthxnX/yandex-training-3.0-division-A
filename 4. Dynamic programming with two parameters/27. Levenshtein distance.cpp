#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    n = s1.length();
    m = s2.length();
    vector <vector <int> > d(n + 1, vector <int>(m + 1));

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            if (i == 0 && j == 0)
                d.at(i).at(j) = 0;
            if (i > 0 && j == 0)
                d.at(i).at(j) = i;
            if (i == 0 && j > 0)
                d.at(i).at(j) = j;
            if (i > 0 && j > 0)
                d.at(i).at(j) = min(min(d.at(i).at(j - 1) + 1, d.at(i - 1).at(j) + 1), d.at(i - 1).at(j - 1) + (s1.at(i - 1) == s2.at(j - 1) ? 0 : 1));
        }

    cout << d.at(n).at(m) << endl;

    return 0;
}
