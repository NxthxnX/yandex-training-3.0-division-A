#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > edges(n);
    vector <bool> been(n, false);
    stack <int> dfs_stack;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        edges.at(b - 1).push_back(a - 1);
    }

    dfs_stack.push(0);

    while (dfs_stack.size()) {
        int v = dfs_stack.top();
        dfs_stack.pop();

        if (been.at(v))
            continue;

        for (const int& u : edges.at(v))
            dfs_stack.push(u);

        been.at(v) = true;
    }

    for (int i = 0; i < n; ++i)
        if (been.at(i))
            cout << i + 1 << ' ';
    cout << endl;

    return 0;
}
