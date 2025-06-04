#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;

int main() {
	int a, b;
	vector <int> prevnum(10000, -1);
	vector <int> dist(10000, numeric_limits<int>::max());
	vector <bool> been(10000, false);
	queue <int> q;
	cin >> a >> b;
	prevnum.at(a) = a;
	q.push(a);
	dist.at(a) = 0;

	while (q.size()) {
		int cur = q.front(), next;
		q.pop();
		if (been.at(cur))
			continue;
		if (cur == b)
			break;

		int firstnum = cur / 1000, lastnum = cur % 10;

		if (firstnum != 9) {
			next = cur + 1000;
			if (dist.at(next) > dist.at(cur) + 1) {
				dist.at(next) = dist.at(cur) + 1;
				q.push(next);
				prevnum.at(next) = cur;
			}
		}
		if (lastnum != 1) {
			next = cur - 1;
			if (dist.at(next) > dist.at(cur) + 1) {
				dist.at(next) = dist.at(cur) + 1;
				q.push(next);
				prevnum.at(next) = cur;
			}
		}

		next = cur / 10 + 1000 * lastnum;
		if (dist.at(next) > dist.at(cur) + 1) {
			dist.at(next) = dist.at(cur) + 1;
			q.push(next);
			prevnum.at(next) = cur;
		}


		next = cur * 10 % 10000 + firstnum;
		if (dist.at(next) > dist.at(cur) + 1) {
			dist.at(next) = dist.at(cur) + 1;
			q.push(next);
			prevnum.at(next) = cur;
		}

		been.at(cur) = true;
	}

	int cur = b;
	vector <int> ans;
	ans.push_back(cur);
	do {
		cur = prevnum.at(cur);
		ans.push_back(cur);
	} while (cur != prevnum.at(cur));

	copy(ans.rbegin(), ans.rend(), ostream_iterator<int>(cout, "\n"));

	return 0;
}
