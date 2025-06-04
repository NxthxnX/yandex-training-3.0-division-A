#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <limits>

using namespace std;

struct Pos {
	// dir: 0 - still, 1 - up, 2 - down, 3 - left, 4 - right
	int dir, i, j;
	Pos(int dir, int i, int j) : dir(dir), i(i), j(j) {}
};

int main() {
	int n, m, ansdir{}, ansi{}, ansj{};
	cin >> n >> m;
	vector <vector <int> > labyrinth(n + 2, vector <int>(m + 2, 1));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> labyrinth.at(i).at(j);

	vector <vector <vector <int> > > dist(5, vector <vector <int> >(n + 2, vector <int>(m + 2, numeric_limits<int>::max())));
	vector <vector <vector <bool> > > been(5, vector <vector <bool> >(n + 2, vector <bool>(m + 2, false)));
	array <int, 5> di{ 0, -1, 1, 0, 0 }, dj{ 0, 0, 0, -1, 1 };
	deque <Pos> dq;
	dq.push_front(Pos(0, 1, 1));
	dist.at(0).at(1).at(1) = 0;

	while (dq.size()) {
		Pos cur = dq.front();
		dq.pop_front();
		if (been.at(cur.dir).at(cur.i).at(cur.j))
			continue;
		been.at(cur.dir).at(cur.i).at(cur.j) = true;

		if (cur.dir == 0) {
			for (int d = 1; d <= 4; ++d)
				if (dist.at(d).at(cur.i).at(cur.j) > dist.at(cur.dir).at(cur.i).at(cur.j)) {
					dist.at(d).at(cur.i).at(cur.j) = dist.at(cur.dir).at(cur.i).at(cur.j);
					dq.push_front(Pos(d, cur.i, cur.j));
				}
		}
		else {
			if (labyrinth.at(cur.i).at(cur.j) == 2) {
				ansdir = cur.dir;
				ansi = cur.i;
				ansj = cur.j;
				break;
			}
			if (labyrinth.at(cur.i + di.at(cur.dir)).at(cur.j + dj.at(cur.dir)) == 1) {
				if (dist.at(0).at(cur.i).at(cur.j) > dist.at(cur.dir).at(cur.i).at(cur.j) + 1) {
					dist.at(0).at(cur.i).at(cur.j) = dist.at(cur.dir).at(cur.i).at(cur.j) + 1;
					dq.push_back(Pos(0, cur.i, cur.j));
				}
			}
			else if (dist.at(cur.dir).at(cur.i + di.at(cur.dir)).at(cur.j + dj.at(cur.dir)) > dist.at(cur.dir).at(cur.i).at(cur.j)) {
				dist.at(cur.dir).at(cur.i + di.at(cur.dir)).at(cur.j + dj.at(cur.dir)) = dist.at(cur.dir).at(cur.i).at(cur.j);
				dq.push_front(Pos(cur.dir, cur.i + di.at(cur.dir), cur.j + dj.at(cur.dir)));
			}
		}
	}

	cout << dist.at(ansdir).at(ansi).at(ansj) + 1 << endl;

	return 0;
}
