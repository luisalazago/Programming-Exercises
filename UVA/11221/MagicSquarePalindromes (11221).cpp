#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	int cases, ascii, contador, ver;
	char temp[2];
	bool impresion;
	string frase, temp2, temp3;

	scanf("%d\n", &cases);
	int j = 1;
	while(cases--) {
		contador = 0;
		frase = "";
		getline(cin, temp2);
		for(int i = 0; i < temp2.size(); i++) {
			temp3 = temp2[i];
			strcpy(temp, temp3.c_str());
			ascii = temp[0];
			if(ascii >= 97 && ascii <= 122) {
				frase += temp2[i];
				contador++;
			}
		}

		ver = 0;
		int i = 0;
		int k = frase.size() - 1;
		if(k < 0) k = 0;
		while(k > -1) {
			if(frase[i] == frase[k] && frase[i] != '\0') ver++;
			i++;
			k--;
		}

		cout << "Case #" << j << ":" << endl;
		if(ver == contador) {
			impresion = false;
			for(int i = 0; i * i <= contador; i++) {
				if(i * i == contador) {
					cout << i << endl;
					impresion = true;
					break;
				}
			}

			if(impresion == false) cout << "No magic :(" << endl;
		}
		else cout << "No magic :(" << endl;
		j++;
	}	
	
	return 0;
}