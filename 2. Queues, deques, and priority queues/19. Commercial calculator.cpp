#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

int main() {
	int n;
	double ans = 0;
	multiset <int> nums;
	cin >> n;
	for (int i = 0, a; i < n; ++i) {
		cin >> a;
		nums.insert(a);
	}

	double a, b;
	while (nums.size() > 1) {
		a = *nums.begin();
		nums.erase(nums.begin());
		b = *nums.begin();
		nums.erase(nums.begin());
		ans += (a + b) * 0.05;
		nums.insert(a + b);
	}

	cout << fixed << setprecision(2) << ans << endl;

	return 0;
}
