#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	int n;
	queue <int> begin;
	deque <int> end;
	vector <int> ans;

	cin >> n;
	for (int j = 0; j < n; ++j) {
		char c = 0;
		int i;
		cin >> c;
		if (c == '+') {
			cin >> i;
			end.push_back(i);
			if (end.size() > begin.size()) {
				begin.push(end.front());
				end.pop_front();
			}
		}
		else if (c == '*') {
			cin >> i;
			end.push_front(i);
			if (end.size() > begin.size()) {
				begin.push(end.front());
				end.pop_front();
			}
		}
		else if (c == '-') {
			ans.push_back(begin.front());
			begin.pop();
			if (end.size() > begin.size()) {
				begin.push(end.front());
				end.pop_front();
			}
		}
	}

	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));

	return 0;
}
