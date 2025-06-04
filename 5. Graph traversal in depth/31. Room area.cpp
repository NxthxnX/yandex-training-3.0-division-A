#include <iostream>
#include <vector>
#include <array>
#include <stack>

using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    vector <vector <char> > labyrinth(n, vector <char>(n));
    vector <vector <bool> > been(n, vector <bool>(n, false));
    array <int, 4> di{ -1, 0, 1, 0 }, dj{ 0, 1, 0, -1 };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> labyrinth.at(i).at(j);
    cin >> x >> y;

    stack <pair <int, int> > dfs_stack;
    dfs_stack.push(make_pair(x - 1, y - 1));
    while (dfs_stack.size()) {
        auto [u, v] = dfs_stack.top();
        dfs_stack.pop();
        if (labyrinth.at(u).at(v) == '*' || been.at(u).at(v))
            continue;

        for (int i = 0; i < 4; ++i)
            dfs_stack.push(make_pair(u + di.at(i), v + dj.at(i)));

        been.at(u).at(v) = true;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (been.at(i).at(j))
                ++ans;

    cout << ans << endl;

    return 0;
}
