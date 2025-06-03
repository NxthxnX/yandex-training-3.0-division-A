#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    string a, b, c;
    stringstream ss;
    int ha, ma, sa, hb, mb, sb, hc, mc, sc, timea, timeb, timec, timeans;
    char colon;

    getline(cin, a);
    getline(cin, b);
    getline(cin, c);

    ss << a;
    ss >> ha >> colon >> ma >> colon >> sa;
    ss.str(string{});
    ss.clear();
    timea = ha * 3600 + ma * 60 + sa;

    ss << b;
    ss >> hb >> colon >> mb >> colon >> sb;
    ss.str(string{});
    ss.clear();
    timeb = hb * 3600 + mb * 60 + sb;

    ss << c;
    ss >> hc >> colon >> mc >> colon >> sc;
    ss.str(string{});
    ss.clear();
    timec = hc * 3600 + mc * 60 + sc;
    if (timec < timea)
        timec += 24 * 3600;

    timeans = timeb + (timec - timea + 1) / 2;
    if (timeans >= 24 * 3600)
        timeans -= 24 * 3600;

    cout << setfill('0') << setw(2) << timeans / 3600 << ':'
        << setfill('0') << setw(2) << timeans / 60 % 60 << ':'
        << setfill('0') << setw(2) << timeans % 60;

    return 0;
}
