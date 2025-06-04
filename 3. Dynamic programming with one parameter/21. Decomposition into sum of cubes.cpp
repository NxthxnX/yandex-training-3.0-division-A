#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> cubes(101), ans(max(n, 3) + 1, numeric_limits<int>::max());
    for (int i = 0; i <= 100; ++i)
        cubes.at(i) = i * i * i;
    for (int i = 0; i <= 3; ++i)
        ans.at(i) = i;
    
    for (int i = 4; i <= n; ++i) 
        for (int j = 1; j * j * j <= i; ++j)
            ans.at(i) = min(ans.at(i - cubes.at(j)) + 1, ans.at(i));
    
    cout << ans.at(n) << endl;

    return 0;
}
