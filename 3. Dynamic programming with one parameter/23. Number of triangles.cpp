#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, k;
    cin >> n;
    k = n / 2;
    if (n % 2 == 0)
        cout << k * (k + 1) * (4 * k + 1) / 2 << endl;
    else
        cout << (k + 1) * (4 * k * k + 7 * k + 2) / 2 << endl;

    return 0;
}
