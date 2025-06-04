#include <iostream>
#include <deque>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits>

using namespace std;

int main() {
    int n, k;
    unordered_map <int, set <int> > edges;
    deque <int> curvertices;
    unordered_map <int, int> cost;
    unordered_set <int> seen;

    cin >> n >> k;

    for (int i = 1, r; i <= k; ++i) {
        cin >> r;
        for (int j = 0; j < r; ++j) {
            short a, b;
            cin >> a >> b;
            if (edges.find(a * 2001 + i) == edges.end())
                edges.insert({ a * 2001 + i, set <int>{} });
            edges.at(a * 2001 + i).insert(b * 2001 + i + 4002001 * 0);
            edges.at(a * 2001 + i).insert(a * 2001 + 0 + 4002001 * 0);
            if (edges.find(b * 2001 + i) == edges.end())
                edges.insert({ b * 2001 + i, set <int>{} });
            edges.at(b * 2001 + i).insert(a * 2001 + i + 4002001 * 0);
            edges.at(b * 2001 + i).insert(b * 2001 + 0 + 4002001 * 0);
            if (edges.find(a * 2001 + 0) == edges.end())
                edges.insert({ a * 2001 + 0, set <int>{} });
            edges.at(a * 2001 + 0).insert(a * 2001 + i + 4002001 * 1);
            if (edges.find(b * 2001 + 0) == edges.end())
                edges.insert({ b * 2001 + 0, set <int>{} });
            edges.at(b * 2001 + 0).insert(b * 2001 + i + 4002001 * 1);
        }
    }

    curvertices.push_front(1 * 2001 + 0);
    if (edges.find(1 * 2001 + 0) == edges.end())
        edges.insert({ 1 * 2001 + 0, set <int>{} });
    cost.insert({ 1 * 2001 + 0, 0 });
    while (curvertices.size()) {
        int vert = curvertices.front();
        curvertices.pop_front();
        if (seen.find(vert) != seen.end())
            continue;
        for (const int& adjacent_and_dist : edges.at(vert)) {
            int adjacent = adjacent_and_dist % 4002001;
            int dist = adjacent_and_dist / 4002001;
            if (cost.find(adjacent) == cost.end())
                cost.insert({ adjacent, numeric_limits<int>::max() });
            if (cost.at(vert) + dist < cost.at(adjacent)) {
                cost.at(adjacent) = cost.at(vert) + dist;
                if (dist == 1)
                    curvertices.push_back(adjacent);
                else if (dist == 0)
                    curvertices.push_front(adjacent);
            }
        }
        seen.insert(vert);
    }

    if (cost.find(n * 2001 + 0) != cost.end())
        cout << cost.at(n * 2001 + 0) << endl;
    else
        cout << -1 << endl;

    return 0;
}
