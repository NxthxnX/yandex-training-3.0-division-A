#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

string infix_to_postfix(string infixexpr);

int main() {
	string s, zero_and_one{ "01" };
	getline(cin, s);

	for (int i = 0; i < s.length(); ++i) {
		if (s.at(i) == ' ')
			continue;
		if (zero_and_one.find(s.at(i)) == string::npos) {
			s.insert(s.begin() + i, ' ');
			++i;
			s.insert(s.begin() + i + 1, ' ');
			++i;
		}
	}

	stringstream ss;
	string op;

	s = infix_to_postfix(s);

	stack <string> op_stack;
	ss << s;
	while (ss >> op) {
		if (op.find_first_not_of(zero_and_one) == string::npos) {
			op_stack.push(op);
		}
		else {

			bool b = stoi(op_stack.top());
			if (op == "&" || op == "|" || op == "^")
				op_stack.pop();
			bool a = stoi(op_stack.top());
			op_stack.pop();
			bool c{};
			if (op == "!")
				c = !a;
			else if (op == "&")
				c = a & b;
			else if (op == "|")
				c = a | b;
			else if (op == "^")
				c = a ^ b;
			op_stack.push(to_string(c));
		}
	}

	cout << op_stack.top() << endl;

	return 0;
}

string infix_to_postfix(string infixexpr) {
	map <string, int> prec{ {"!", 4 }, {"&", 3 }, { "|", 2 }, { "^", 2 }, { "(", 1 } };
	stack <string> op_stack;
	vector <string> postfix_vect, token_vect;
	string top_token, ans;

	stringstream ss;
	string op, zero_and_one{ "01" };
	ss << infixexpr;
	while (ss >> op) {
		token_vect.push_back(op);
	}

	for (const string& token : token_vect) {
		if (token.find_first_not_of(zero_and_one) == string::npos) {
			postfix_vect.push_back(token);
		}
		else if (token == "(")
			op_stack.push(token);
		else if (token == ")") {
			top_token = op_stack.top();
			op_stack.pop();
			while (top_token != "(") {
				postfix_vect.push_back(top_token);
				top_token = op_stack.top();
				op_stack.pop();
			}
		}
		else {
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
