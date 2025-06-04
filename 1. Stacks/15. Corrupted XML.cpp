#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <limits>

using namespace std;

bool iscorrectxml(string& xml);

int main() {
	bool flag = true;
	string xml, transform, ans{}, spec_ch{ "<>/" };
	getline(cin, xml);
	for (int i = 0; i < xml.length() && flag; ++i) {
		for (int j = 0; j < 26; ++j) {
			transform = xml;
			transform.at(i) = j + 'a';
			if (iscorrectxml(transform)) {
				ans = transform;
				flag = false;
				break;
			}
		}

		for (int j = 0; j < 3; ++j) {
			transform = xml;
			transform.at(i) = spec_ch.at(j);
			if (iscorrectxml(transform)) {
				ans = transform;
				flag = false;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}

bool iscorrectxml(string& xml) {
	bool ans = true;
	stack <string> tags;
	int i = 0;
	while (i < xml.length()) {
		if (xml.at(i) == '<') {
			int j = i + 1;
			if (j == xml.length())
				return false;

			if (xml.at(j) == '/') {
				++j;
			}

			while (j < xml.length() && xml.at(j) != '>' && 'a' <= xml.at(j) && xml.at(j) <= 'z')
				++j;
			if (j == xml.length() || xml.at(j) != '>' || xml.at(i + 1) == '/' && j == i + 2 || j == i + 1)
				return false;

			if (xml.at(i + 1) != '/') {
				tags.push(xml.substr(i, j - i + 1));
				i = j + 1;
			}
			else {
				if (tags.empty())
					return false;
				string prevtag = tags.top();
				tags.pop();
				if (prevtag != xml.substr(i, j - i + 1).erase(1, 1))
					return false;
				i = j + 1;
			}
		}
		else if ('a' <= xml.at(i) && xml.at(i) <= 'z') {
			++i;
		}
		else {
			return false;
		}
	}
	if (!tags.empty())
		return false;

	return true;
}
