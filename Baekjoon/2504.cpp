#include<iostream>
#include<stack>
#include<string>

using namespace std;
int evaluate();

int main() {
	int result = evaluate();
	cout << result << endl;

	return 0;
}

int evaluate() {
	char elem;
	stack<char> program_stack;
	int context = 1;
	int value = 0;
	char prev = ' ';

	while (cin >> elem) {
		switch (elem) {
		case '(':
			context *= 2;
			program_stack.push(elem);
			break;
		case '[':
			context *= 3;
			program_stack.push(elem);
			break;
		case ')':
			if (program_stack.empty()) return 0;
			if (program_stack.top() == '(')
				program_stack.pop();
			if (prev == '(')
				value += context;
			context /= 2;
			break;
		case ']':
			if (program_stack.empty()) return 0;
			if (program_stack.top() == '[')
				program_stack.pop();
			if (prev == '[')
				value += context;
			context /= 3;
			break;
		}
		prev = elem;
	}

	return program_stack.empty()? value : 0;
}