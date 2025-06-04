#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <limits>

using namespace std;

struct Cell {
	int line, row;
	Cell(int line, int row) : line(line), row(row) {}
};

int main() {
	string start, finish;
	cin >> start >> finish;
	int row1 = start.at(0) - 'a', row2 = finish.at(0) - 'a', line1 = start.at(1) - '1', line2 = finish.at(1) - '1';
	vector <vector <int> > dist(12, vector <int>(12, -1));
	vector <vector <bool> > been(12, vector <bool>(12, false));
	array <int, 8> di{ -2, -2, -1, 1, 2, 2, 1, -1 }, dj{ -1, 1, 2, 2, 1, -1, -2, -2 };
	for (int i = 2; i <= 9; ++i)
		for (int j = 2; j <= 9; ++j)
			dist.at(i).at(j) = numeric_limits<int>::max();

	if ((line1 + row1) % 2 == (line2 + row2) % 2) {
		Cell from = Cell(line1 + 2, row1 + 2), to = Cell(line2 + 2, row2 + 2);
		dist.at(from.line).at(from.row) = 0;
		queue <Cell> q;
		q.push(from);

		while (q.size()) {
			Cell cur = q.front();
			q.pop();
			if (been.at(cur.line).at(cur.row))
				continue;

			if (cur.line == to.line && cur.row == to.row)
				break;

			for (int i = 0; i < 8; ++i) {
				if (dist.at(cur.line + di.at(i)).at(cur.row + dj.at(i)) > dist.at(cur.line).at(cur.row) + 1) {
					dist.at(cur.line + di.at(i)).at(cur.row + dj.at(i)) = dist.at(cur.line).at(cur.row) + 1;
					q.push(Cell(cur.line + di.at(i), cur.row + dj.at(i)));
				}
			}

			been.at(cur.line).at(cur.row) = true;
		}

		cout << dist.at(to.line).at(to.row) / 2 << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}
