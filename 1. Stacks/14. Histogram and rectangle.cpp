#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <long long> h(n + 2);
	vector <int> minleft(n + 2), minright(n + 2);
	for (int i = 1; i <= n; ++i)
		cin >> h.at(i);
	h.at(0) = 0;
	h.at(n + 1) = 0;

	stack <pair <long long, int> > stackheight;

	for (int i = n; i >= 0; --i) {
		while (stackheight.size() && stackheight.top().first > h.at(i)) {
			minleft.at(stackheight.top().second) = i;
			stackheight.pop();
		}
		stackheight.push(make_pair(h.at(i), i));
	}
	stackheight = stack<pair <long long, int> >{};

	for (int i = 1; i <= n + 1; ++i) {
		while (stackheight.size() && stackheight.top().first > h.at(i)) {
			minright.at(stackheight.top().second) = i;
			stackheight.pop();
		}
		stackheight.push(make_pair(h.at(i), i));
	}
	stackheight = stack<pair <long long, int> >{};
	
	long long ans = numeric_limits<long long>::min();
	for (int i = 1; i <= n; ++i)
		ans = max((minright.at(i) - minleft.at(i) - 1) * h.at(i), ans);

	cout << ans << endl;

	return 0;
}
