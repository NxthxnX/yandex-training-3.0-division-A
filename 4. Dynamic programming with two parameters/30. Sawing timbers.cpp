#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
	int l, n;
	cin >> l >> n;
	vector <int> places(n + 2);
	places.at(0) = 0;
	places.at(n + 1) = l;
	for (int i = 1; i <= n; ++i)
		cin >> places.at(i);
	vector <vector <int> > ans(n + 2, vector <int>(n + 2, 0));

	for (int j = 2; j < n + 2; ++j)
		for (int i = j - 2; i >= 0; --i) {
			ans.at(i).at(j) = numeric_limits<int>::max();
			for (int k = i + 1; k <= j - 1; ++k)
				ans.at(i).at(j) = min(ans.at(i).at(k) + ans.at(k).at(j), ans.at(i).at(j));
			ans.at(i).at(j) += places.at(j) - places.at(i);
		}

	cout << ans.at(0).at(n + 1) << endl;

	return 0;
}
