#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iterator>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n), max_len(n), prev(n);
	for (int i = 0; i < n; ++i)
		cin >> a.at(i);

	for (int i = 0; i < n; ++i) {
		max_len.at(i) = 1;
		prev.at(i) = -1;
		for (int j = 0; j < i; ++j)
			if (a.at(j) < a.at(i) && max_len.at(j) + 1 > max_len.at(i)) {
				max_len.at(i) = max_len.at(j) + 1;
				prev.at(i) = j;
			}
	}

	int pos = 0, len = max_len.at(0);
	for (int i = 0; i < n; ++i)
		if (max_len.at(i) > len) {
			pos = i;
			len = max_len.at(i);
		}

	vector <int> ans;
	while (pos != -1) {
		ans.push_back(a.at(pos));
		pos = prev.at(pos);
	}

	copy(ans.rbegin(), ans.rend(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
