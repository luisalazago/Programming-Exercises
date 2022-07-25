#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

int main() {
	int cases;
	bool flag;
	string line;
	stack<char> pila;

	cin >> cases;
	cin.ignore();
	while(cases--) {
		getline(cin, line);
		flag = true;
		for(int i = 0; i < line.size(); ++i) {
			if(line[i] == '(' || line[i] == '[') pila.push(line[i]);
			else if((line[i] == ')' || line[i] == ']') && !pila.size()) {
				flag = false;
				break;
			}
			else if((line[i] == ')' && pila.top() == '(') || (line[i] == ']' && pila.top() == '[')) pila.pop();
			else {
				flag = false;
				break;
			}
		}
		if(flag && pila.size() == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
		while(pila.size()) pila.pop();
	}
	return 0;
}