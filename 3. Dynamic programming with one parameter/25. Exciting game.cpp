#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b)
        swap(a, b);
    vector <int> ans(n + 1, numeric_limits<int>::max());
    ans.at(0) = 0;
    ans.at(1) = 0;
    for (int i = 2; i <= n; ++i) 
        for (int j = 1; j <= i / 2; ++j)
            ans.at(i) = min(max(ans.at(j) + b, ans.at(i - j) + a), ans.at(i));
    
    cout << ans.at(n) << endl;

    return 0;
}
