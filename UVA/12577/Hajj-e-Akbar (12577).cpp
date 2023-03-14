#include <iostream>
#include <string>

#define INFINITO 2000000
#define endl '\n'

using namespace std;

int main() {
	int i;
	string palabra;

	i = 1;
	cin >> palabra;
	while(palabra != "*") {
		cout << "Case "<< i << ": ";
		if(palabra == "Hajj") cout << "Hajj-e-Akbar" << endl;
		else if(palabra == "Umrah") cout << "Hajj-e-Asghar" << endl;
		cin >> palabra;
		++i;
	}
	return 0;
}