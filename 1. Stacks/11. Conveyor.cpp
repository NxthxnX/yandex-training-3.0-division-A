#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        vector <float> crates(k), crates_sorted(k);
        for (int j = 0; j < k; ++j)
            cin >> crates.at(j);
        copy(crates.begin(), crates.end(), crates_sorted.begin());
        sort(crates_sorted.begin(), crates_sorted.end());
        stack <float> nums;

        for (int j = 0, ii = 0; j < k; ++j) {
            nums.push(crates.at(j));
            while (nums.size() && nums.top() == crates_sorted.at(ii)) {
                nums.pop();
                ++ii;
            }
        }

        ans.at(i) = (nums.empty() ? 1 : 0);
    }

    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));

    return 0;
}
