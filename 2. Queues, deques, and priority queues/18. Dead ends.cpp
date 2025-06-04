#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> in(n), out(n);

    for (int i = 0; i < n; ++i)
        cin >> in.at(i) >> out.at(i);

    set <int> deadends;
    for (int i = 0; i < k; ++i)
        deadends.insert(i);

    bool correct = true;
    int incorrectnum{};
    vector<int> ans(n);
    multiset <pair <int, int> > cur_trains;
    for (int i = 0; i < n; ++i) {
        for (auto j = cur_trains.begin(); j != cur_trains.end(); j = cur_trains.erase(j))
            if (j->first < in.at(i))
                deadends.insert(j->second);
            else
                break;

        if (deadends.empty()) {
            correct = false;
            incorrectnum = i + 1;
            break;
        }
        ans.at(i) = *deadends.begin() + 1;
        cur_trains.insert({ out.at(i), *deadends.begin() });
        deadends.erase(deadends.begin());
    }

    if (correct)
        copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));
    else
        cout << 0 << ' ' << incorrectnum << endl;

	return 0;
}
