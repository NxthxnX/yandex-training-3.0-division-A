#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>

using namespace std;

void bfs_algo(int v, vector <vector <array <int, 2> > >& bfs, unordered_map <int, set <int> >& edges);

int main() {
    int n, k, m;
    const int INF = 1000000;
    cin >> n >> k;
    vector <vector <array <int, 2> > > bfs(n, vector <array <int, 2> >(n, array <int, 2>{ INF, INF }));
    unordered_map <int, set <int> > edges;
    vector <int> start(k), finish(k);

    for (int i = 0, a, b; i < k; ++i) {
        cin >> a >> b;
        --a;
        --b;
        start.at(i) = a;
        finish.at(i) = b;
        if (edges.find(a) == edges.end())
            edges.insert({ a, set <int>{} });
        edges.at(a).insert(b);
        if (edges.find(b) == edges.end())
            edges.insert({ b, set <int>{} });
        edges.at(b).insert(a);
    }

    cin >> m;
    vector <int> robots(m);
    for (int i = 0, r; i < m; ++i) {
        cin >> r;
        robots.at(i) = r - 1;
    }

    for (int i = 0; i < n; ++i)
        bfs.at(i).at(i).at(0) = 0;

    for (int i = 0; i < m; ++i)
        bfs_algo(robots.at(i), bfs, edges);

    int ans = INF;
    for (int i = 0; i < k; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            cur = max(min(min(bfs.at(robots.at(j)).at(start.at(i)).at(0), bfs.at(robots.at(j)).at(start.at(i)).at(1)), \
                min(bfs.at(robots.at(j)).at(finish.at(i)).at(0), bfs.at(robots.at(j)).at(finish.at(i)).at(1))) + 1, cur);
        }
        ans = min(cur, ans);
    }
    for (int i = 0; i < n; ++i) {
        int leneven = 0, lenodd = 0;
        for (int j = 0; j < m; ++j) {
            leneven = max(bfs.at(robots.at(j)).at(i).at(0), leneven);
            lenodd = max(bfs.at(robots.at(j)).at(i).at(1), lenodd);
        }
        ans = min(min(leneven, lenodd), ans);
    }

    if (ans < INF)
        cout << static_cast<float>(ans) / 2 << endl;
    else
        cout << -1 << endl;

    return 0;
}

void bfs_algo(int v, vector <vector <array <int, 2> > >& bfs, unordered_map <int, set <int> >& edges) {
    queue <int> line;
    line.push(v);

    while (line.size()) {
        int cur = line.front();
        line.pop();

        if (edges.find(cur) == edges.end()) {
            continue;
        }
        for (const int& adjacent : edges.at(cur)) {
            if (bfs.at(v).at(adjacent).at(0) > bfs.at(v).at(cur).at(1) + 2) {
                bfs.at(v).at(adjacent).at(0) = bfs.at(v).at(cur).at(1) + 2;
                line.push(adjacent);
            }
            if (bfs.at(v).at(adjacent).at(1) > bfs.at(v).at(cur).at(0) + 2) {
                bfs.at(v).at(adjacent).at(1) = bfs.at(v).at(cur).at(0) + 2;
                line.push(adjacent);
            }
        }
    }
}
