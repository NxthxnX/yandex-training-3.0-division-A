#include <iostream>
#include <vector>

using namespace std;

int main() {
	int m, n, ans;
	cin >> m >> n;
	ans = n;
	vector <pair <int, int> > sectors(n);
	for (int i = 0, a, b; i < n; ++i) {
		cin >> a >> b;
		sectors.at(i) = make_pair(a, b);
	}

	for (int i = 0; i < n; ++i) {
		bool intersect = false;
		for (int j = i + 1; j < n; ++j)
			if (sectors.at(j).first <= sectors.at(i).second && sectors.at(j).second >= sectors.at(i).first)
				intersect = true;
		if (intersect)
			--ans;
	}

	cout << ans << endl;

	return 0;
}
