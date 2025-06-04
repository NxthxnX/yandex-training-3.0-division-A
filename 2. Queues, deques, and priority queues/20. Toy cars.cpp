#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
	int n, k, p, ans = 0;
	cin >> n >> k >> p;
	vector <int> cars(p), next_use(p), last_use(n, p);
	for (int i = 0; i < p; ++i) {
		cin >> cars.at(i);
		--cars.at(i);
	}

	for (int i = p - 1; i >= 0; --i) {
		next_use.at(i) = last_use.at(cars.at(i));
		last_use.at(cars.at(i)) = i;
	}

	unordered_map <int, int> keys;
	for (int i = 0; i < n; ++i)
		keys.insert({ i, 0 });
		
	multiset <pair <int, int>, greater<> > cur;

	for (int i = 0; i < p; ++i) {
		if (cur.size() < k) {
			if (cur.find(make_pair(keys.at(cars.at(i)), cars.at(i))) != cur.end()) {
				cur.erase(make_pair(keys.at(cars.at(i)), cars.at(i)));
				cur.insert(make_pair(next_use.at(i), cars.at(i)));
				keys.at(cars.at(i)) = next_use.at(i);
			}
			else {
				cur.insert(make_pair(next_use.at(i), cars.at(i)));
				keys.at(cars.at(i)) = next_use.at(i);
				++ans;
			}
		}
		else {
			if (cur.find(make_pair(keys.at(cars.at(i)), cars.at(i))) != cur.end()) {
				cur.erase(make_pair(keys.at(cars.at(i)), cars.at(i)));
				cur.insert(make_pair(next_use.at(i), cars.at(i)));
				keys.at(cars.at(i)) = next_use.at(i);
			}
			else {
				cur.erase(cur.begin());
				cur.insert(make_pair(next_use.at(i), cars.at(i)));
				keys.at(cars.at(i)) = next_use.at(i);
				++ans;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
