#include <iostream>
#include <vector>

using namespace std;

struct bigint {

    static const long long BASE = 1e9;
    static const long long SIZE = 10;

    long long digits[SIZE];

    bigint(long long x) {
        for (int i = 0; i < SIZE; i++) {
            digits[i] = 0;
        }

        int next = 0;
        while (x) {
            digits[next++] = x % BASE;
            x /= BASE;
        }
    }

    void operator+=(const bigint& other) {
        for (int i = 0; i < SIZE; i++) {
            digits[i] += other.digits[i];
        }

        for (int i = 0; i < SIZE - 1; i++) {
            if (digits[i] >= BASE) {
                digits[i] -= BASE;
                digits[i + 1]++;
            }
        }
    }

    bigint operator+(const bigint& other) {
        bigint n(*this);
        n += other;
        return n;
    }
};

ostream& operator<<(ostream& out, const bigint& num);

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <bigint> > ans(n + 3, vector <bigint>(m + 3, 0));

	int i = 2, j = 2;
	ans.at(i).at(j) = 1;
	while (i < n + 1 || j < m + 2) {
		int x = i, y = j;
		while (x >= 2 && y < m + 2) {
			ans.at(x).at(y) += ans.at(x - 2).at(y + 1) + ans.at(x + 1).at(y - 2) + ans.at(x - 2).at(y - 1) + ans.at(x - 1).at(y - 2);
			--x;
			++y;
		}
		if (i < n + 1)
			++i;
		else
			++j;
	}

	cout << ans.at(n + 1).at(m + 1) << endl;

	return 0;
}

ostream& operator<<(ostream& out, const bigint& num) {
    string result;

    char buffer[10];

    for (int i = bigint::SIZE - 1; i >= 0; i--) {
        sprintf(buffer, "%09d", num.digits[i]);
        result += buffer;
    }

    int first_idx = result.find_first_not_of('0');
    if (first_idx == string::npos) {
        out << "0";
    }
    else {
        out << result.substr(first_idx);
    }

    return out;
}
