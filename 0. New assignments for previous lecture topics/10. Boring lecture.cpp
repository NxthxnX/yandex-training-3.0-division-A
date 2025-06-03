#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    array <long long, 26> lttrs{};

    for (long long i = 0; i < s.length(); ++i)
        lttrs.at(s.at(i) - 'a') += (i + 1) + (s.length() - i) - 1 + i * (s.length() - i - 1);

    for (int i = 0; i < 26; ++i)
        if (lttrs.at(i))
            cout << static_cast<char>(i + 'a') << ": " << lttrs.at(i) << endl;

    return 0;
}
