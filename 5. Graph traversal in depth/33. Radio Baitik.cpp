#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iterator>

using namespace std;

struct Dot {
    int x, y;
    Dot(int x, int y) : x(x), y(y) {}
};

bool isbipartite(int v, int c, vector <vector <int> >& graph, vector <int>& colors);

int main() {
    int n;
    cin >> n;
    vector <Dot> towers(n, Dot(0, 0));
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        towers.at(i) = Dot(x, y);
    }

    vector <vector <int> > graph(n);
    vector <int> colors(n), ans(n);
    double l = 0, r = 10000 * sqrt(2), m;
    while (r - l > 1e-9) {
        m = (l + r) / 2;
        fill(colors.begin(), colors.end(), 0);
        bool correct = true;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if ((towers.at(i).x - towers.at(j).x) * (towers.at(i).x - towers.at(j).x) +
                    (towers.at(i).y - towers.at(j).y) * (towers.at(i).y - towers.at(j).y) < 4 * m * m) {
                    graph.at(i).push_back(j);
                    graph.at(j).push_back(i);
                }
        for (int i = 0; i < n; ++i)
            if (colors.at(i) == 0 && !isbipartite(i, 1, graph, colors)) {
                correct = false;
                break;
            }

        if (correct) {
            l = m;
            copy(colors.begin(), colors.end(), ans.begin());
        }
        else
            r = m;

        for (auto& v : graph)
            v.clear();
    }

    cout << fixed << setprecision(8) << l << endl;
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

bool isbipartite(int v, int c, vector <vector <int> >& graph, vector <int>& colors) {
    colors.at(v) = c;

    for (int u : graph.at(v)) {
        if (colors.at(u) == 0 && !isbipartite(u, 3 - c, graph, colors))
            return false;
        if (colors.at(u) == c) {
            return false;
        }
    }
    return true;
}
