#include <iostream>
#include <limits>

using namespace std;

int main() {
    int k, xmin = numeric_limits<int>::max(), ymin = numeric_limits<int>::max(), xmax = numeric_limits<int>::min(), ymax = numeric_limits<int>::min();
    cin >> k;
    for (int i = 0, x, y; i < k; ++i) {
        cin >> x >> y;
        xmin = min(x, xmin);
        ymin = min(y, ymin);
        xmax = max(x, xmax);
        ymax = max(y, ymax);
    }

    cout << xmin << ' ' << ymin << ' ' << xmax << ' ' << ymax << endl;

    return 0;
}
