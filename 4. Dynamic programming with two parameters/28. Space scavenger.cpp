#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    array <char, 6> chs{ 'N', 'S', 'W', 'E', 'U', 'D' };
    array <string, 6> rules;
    array <array <int, 6>, 6> dir_occurence{};
    map <char, int> ctoi;
    for (int i = 0; i < 6; ++i)
        ctoi.insert({ chs.at(i), i });

    string s;
    for (int i = 0; i < 6; ++i) {
        getline(cin, s);
        rules.at(i) = s;
    }

    for (int i = 0; i < 6; ++i)
        for (const char& c : rules.at(i))
            ++dir_occurence.at(i).at(ctoi.at(c));

    char dir;
    int param;
    cin >> dir >> param;

    vector <array <int, 6> > count(param);
    for (int i = 0; i < param; ++i)
        fill_n(count.at(i).begin(), 6, 1);

    for (int i = 1; i < param; ++i)
        for (int parent = 0; parent < 6; ++parent)
            for (int child = 0; child < 6; ++child)
                count.at(i).at(parent) += count.at(i - 1).at(child) * dir_occurence.at(parent).at(child);

    cout << count.at(param - 1).at(ctoi.at(dir)) << endl;

    return 0;
}
