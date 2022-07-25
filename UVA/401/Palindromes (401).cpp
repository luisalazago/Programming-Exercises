#include <iostream>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	FAST_IO;
	int regular, mirrored_string, palindrome;
	string palabra, palabra2;

	while(cin >> palabra) {
		regular = mirrored_string = palindrome = 0;
		palabra2 = palabra;
		reverse(palabra2.begin(), palabra2.end());
		for(int i = 0; i < palabra2.size(); ++i) if(palabra2[i] == palabra[i]) ++regular;
		
		for(int i = 0; i < palabra2.size(); ++i) {
			if(palabra2[i] == 'A' || palabra2[i] == 'H' || palabra2[i] == 'I' || palabra2[i] == 'M' ||
			   palabra2[i] == 'T' || palabra2[i] == 'U' || palabra2[i] == 'V' || palabra2[i] == 'X' ||
			   palabra2[i] == 'Y' || palabra2[i] == 'W' || palabra2[i] == '1' || palabra2[i] == '8') {
				++mirrored_string;
				++palindrome;
			}
			else if(palabra2[i] == 'E' || palabra2[i] == '3') {
				if(palabra2[i] == 'E') palabra2[i] = '3';
				else palabra2[i] = 'E';
				++mirrored_string;
			}
			else if(palabra2[i] == 'J' || palabra2[i] == 'L') {
				if(palabra2[i] == 'J') palabra2[i] = 'L';
				else palabra2[i] = 'J';
				++mirrored_string;
			}
			else if(palabra2[i] == 'O' || palabra2[i] == '0') {
				palabra2[i] = 'O';
				++mirrored_string;
				++palindrome;
			}
			else if(palabra2[i] == 'S' || palabra2[i] == '2') {
				if(palabra2[i] == 'S') palabra2[i] = '2';
				else palabra2[i] = 'S';
				++mirrored_string;
			}
			else if(palabra2[i] == 'Z' || palabra2[i] == '5') {
				if(palabra2[i] == 'Z') palabra2[i] = '5';
				else palabra2[i] = 'Z';
				++mirrored_string;
			}
		}

		for(int i = 0; i < palabra2.size(); ++i) {
			if(palabra[i] != palabra2[i]) {
				mirrored_string = 0;
				palindrome = 0;
				break;
			}
		}

		cout << palabra << " -- ";
		if(regular == palabra2.size() && mirrored_string != palabra2.size()) cout << "is a regular palindrome." << endl;
		else if(regular == palabra2.size() && palindrome == palabra2.size()) cout << "is a mirrored palindrome." << endl;
		else if(mirrored_string == palabra2.size() && mirrored_string > palindrome) cout << "is a mirrored string." << endl;
		else cout << "is not a palindrome." << endl;
		cout << endl;
	}
	return 0;
}