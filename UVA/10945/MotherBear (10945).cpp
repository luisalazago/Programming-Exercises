#include <iostream>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	FAST_IO;
	char temp[2];
	int ascii, ver;
	string frase, frase2;

	getline(cin, frase);
	while(frase != "DONE") {
		frase2 = "";
		for(int i = 0; i < frase.size(); ++i) {
			temp[0] = frase[i];
			ascii = temp[0];
			if((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
				if(ascii >= 65 && ascii <= 90) {
					ascii += 32;
					temp[0] = (char)ascii;
				}			
				frase2 += temp[0];
			}
		}

		if(frase.size() > 0 && frase2.size() == 0) frase = "";

		ver = 0;
		int i = 0;
		int j = frase2.size() - 1;
		while(i < frase2.size() && j >= 0) {
			if(frase2[i] == frase2[j]) ++ver;
			else {
				ver = 0;
				break;
			}
			++i;
			--j;
		}

		if(!ver && frase2.size() != 0) cout << "Uh oh.." << endl;
		else if(frase.size() == 0) cout << "You won't be eaten!" << endl;
		else cout << "You won't be eaten!" << endl;

		getline(cin, frase);
	}

	return 0;
}