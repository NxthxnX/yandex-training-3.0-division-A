#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n), ans(n - k + 1);
	for (int i = 0; i < n; ++i)
		cin >> a.at(i);

	deque <int> dq;
	for (int i = 0; i < k - 1; ++i) {
		while (dq.size() && dq.back() > a.at(i))
			dq.pop_back();
		dq.push_back(a.at(i));
	}
	for (int i = k - 1; i < n; ++i) {
		while (dq.size() && dq.back() > a.at(i))
			dq.pop_back();
		dq.push_back(a.at(i));
		ans.at(i - k + 1) = dq.front();
		if (dq.front() == a.at(i - k + 1))
			dq.pop_front();
	}

	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));

	return 0;
}
