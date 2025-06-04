#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

string infix_to_postfix(string infixexpr);

int main() {
	string s, digits{ "0123456789" };
	getline(cin, s);

	for (int i = 0; i < s.length(); ++i) {
		if (s.at(i) == ' ')
			continue;
		if (digits.find(s.at(i)) == string::npos) {
			s.insert(s.begin() + i, ' ');
			++i;
			s.insert(s.begin() + i + 1, ' ');
			++i;
		}
	}

	bool correct = true, prevnum = false;
	stringstream ss;
	string op;

	ss << s;
	while (ss >> op) {
		if (op.find_first_not_of(digits) == string::npos) {
			if (prevnum) {
				correct = false;
				break;
			}
			prevnum = true;
		}
		else
			prevnum = false;
	}
	ss.str(string{});
	ss.clear();

	s = infix_to_postfix(s);

	if (correct)
		correct = (s == "" ? false : true);
	stack <string> op_stack;
	ss << s;
	while (ss >> op) {
		if (op.find_first_not_of(digits) == string::npos) {
			if (op.find_first_not_of("0") == string::npos && op.length() != 1) {
				correct = false;
				break;
			}
			op_stack.push(op);
		}
		else {
			if (op_stack.size() <= 1) {
				correct = false;
				break;
			}
			int b = stoi(op_stack.top());
			op_stack.pop();
			int a = stoi(op_stack.top());
			op_stack.pop();
			int c{};
			if (op == "*")
				c = a * b;
			else if (op == "+")
				c = a + b;
			else if (op == "-")
				c = a - b;
			op_stack.push(to_string(c));
		}
	}

	if (op_stack.size() == 1 && correct)
		cout << op_stack.top() << endl;
	else
		cout << "WRONG\n";

	return 0;
}

string infix_to_postfix(string infixexpr) {
	map <string, int> prec{ { "*", 3 }, { "+", 2 }, { "-", 2 }, { "(", 1 } };
	stack <string> op_stack;
	vector <string> postfix_vect, token_vect;
	string top_token, ans;

	stringstream ss;
	string op, digits{ "0123456789" };
	ss << infixexpr;
	while (ss >> op) {
		token_vect.push_back(op);
	}

	for (const string& token : token_vect) {
		if (token.find_first_not_of(digits) == string::npos) {
			postfix_vect.push_back(token);
		}
		else if (token == "(")
			op_stack.push(token);
		else if (token == ")") {
			if (op_stack.empty())
				return "";
			top_token = op_stack.top();
			op_stack.pop();
			while (top_token != "(") {
				if (op_stack.empty())
					return "";
				postfix_vect.push_back(top_token);
				top_token = op_stack.top();
				op_stack.pop();
			}
		}
		else {
			if (prec.find(token) == prec.end())
				return "";
			while (!op_stack.empty() && prec.at(op_stack.top()) >= prec.at(token)) {
				postfix_vect.push_back(op_stack.top());
				op_stack.pop();
			}
			op_stack.push(token);
		}
	}

	while (!op_stack.empty()) {
		postfix_vect.push_back(op_stack.top());
		op_stack.pop();
	}

	for (const string& s : postfix_vect)
		ans += s + " ";

	return ans;
}
