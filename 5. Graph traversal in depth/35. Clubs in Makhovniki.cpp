#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <vector <int> > graph(n);
	vector <int> needed(n, 0), ans;
	set <int, greater<> > groups;

	for (int i = 0, k; i < n; ++i) {
		cin >> k;
		for (int j = 0, a; j < k; ++j) {
			cin >> a;
			graph.at(i).push_back(a - 1);
			++needed.at(a - 1);
		}
	}

	for (int i = 0; i < n; ++i)
		if (needed.at(i) == 0)
			groups.insert(i);

	while (groups.size()) {
		int g = *groups.begin();
		groups.erase(g);
		for (const int& a : graph.at(g)) {
			--needed.at(a);
			if (needed.at(a) == 0)
				groups.insert(a);
		}
		ans.push_back(g + 1);
	}

	copy(ans.rbegin(), ans.rend(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
