#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    map <char, int> histogram;
    while (getline(cin, s)) {
        for (const char& c : s)
            if (c != ' ') {
                if (histogram.find(c) == histogram.end())
                    histogram.insert({ c, 0 });
                ++histogram.at(c);
            }
    }

    const auto [maxkey, maxval] = *max_element(histogram.begin(), histogram.end(), [](const auto& p1, const auto& p2) { return p1.second < p2.second; });

    for (int i = maxval; i > 0; --i) {
        for (const auto& [key, val] : histogram) {
            if (val >= i)
                cout << '#';
            else
                cout << ' ';
        }
        cout << endl;
    }

    for (const auto& [key, val] : histogram) {
        cout << key;
    }
    cout << endl;

    return 0;
}
