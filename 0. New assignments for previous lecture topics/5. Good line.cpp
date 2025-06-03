#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> lttrs(n);
	for (int i = 0; i < n; ++i)
		cin >> lttrs.at(i);
	long long pairlttr, ans = 0;
	for (int i = 0; i < lttrs.size() - 1; ++i) {
		pairlttr = min(lttrs.at(i), lttrs.at(i + 1));
		ans += pairlttr;
	}

	cout << ans << endl;

	return 0;
}
