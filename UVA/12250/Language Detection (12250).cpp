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
	while(palabra != "#") {
		cout << "Case " << i << ": ";
		if(palabra == "HELLO") cout << "ENGLISH" << endl;
		else if(palabra == "HOLA") cout << "SPANISH" << endl;
		else if(palabra == "HALLO") cout << "GERMAN" << endl;
		else if(palabra == "BONJOUR") cout << "FRENCH" << endl;
		else if(palabra == "CIAO") cout << "ITALIAN" << endl;
		else if(palabra == "ZDRAVSTVUJTE") cout << "RUSSIAN" << endl;
		else cout << "UNKNOWN" << endl;
		cin >> palabra;
		++i;
	}
	return 0;
}