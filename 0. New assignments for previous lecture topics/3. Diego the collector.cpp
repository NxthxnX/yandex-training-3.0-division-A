#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	int n, k;
	cin >> n;
	set <int> setstick;
	vector <int> stickers;
	for (int i = 0, a; i < n; ++i) {
		cin >> a;
		setstick.insert(a);
	}

	for (const int& a : setstick)
		stickers.push_back(a);
	
	setstick.clear();

	cin >> k;
	vector <int> ans(k);
	for (int i = 0, p; i < k; ++i) {
		cin >> p;
		ans.at(i) = distance(stickers.begin(), lower_bound(stickers.begin(), stickers.end(), p));
	}

	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
	cout << endl;

	return 0;
}
