#include <iostream>

using namespace std;

int main() {
	int n, k, row, seat, gnrlseat, row1, row2;
	cin >> n >> k >> row >> seat;
	gnrlseat = (row - 1) * 2 + seat;
	row1 = (gnrlseat + k + 1) / 2;
	row2 = (gnrlseat - k + 1) / 2;
	if (gnrlseat + k <= n && row2 - row <= row - row1)
		cout << row1 << ' ' << (gnrlseat + k + 1) % 2 + 1 << endl;
	else if (gnrlseat - k > 0)
		cout << row2 << ' ' << (gnrlseat - k + 1) % 2 + 1 << endl;
	else
		cout << -1 << endl;

	return 0;
}
