#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stdio.h>

using namespace std;

void sortString(string& palabra) {
	int charCount[30] = {0};
	string temp = "";
	for(int i = 0; i < palabra.size(); ++i) {
		charCount[palabra[i] - 'a']++;
	}
	for(int i = 0; i < 30; ++i) {
		for(int j = 0; j < charCount[i]; ++j) {
			temp += (char)('a' + i);
		}
	}
	palabra = temp;
}

int main() {
	int suma, ver;
	char temp;
	string palabra, temp2;
	string::iterator it;
	vector<string> diccionario;
	set<string> palabras;
	set<string>::iterator jt;

	cin >> palabra;
	while(palabra != "#") {
		diccionario.push_back(palabra);
		cin >> palabra;
	}

	scanf("%c", &temp);
	scanf("%c", &temp);
	while((int)temp != 35) {
		palabra = "";
		suma = 0;
		while((int)temp != 10){
			if((int)temp >= 97 && (int)temp <= 122) palabra += temp;
			scanf("%c", &temp);
		}	
		sort(palabra.begin(), palabra.end());

		int k = 0;
		for(int i = 0; i < diccionario.size(); ++i) {
			ver = 0;
			temp2 = palabra;
			for(int j = 0; j < diccionario[i].size(); ++j) {
				it = lower_bound(temp2.begin(), temp2.end(), diccionario[i][j]);
				if((*it) == diccionario[i][j]) {
					++ver;
					(*it) = '1';
					sortString(temp2);
				}
			}
			if(ver == diccionario[i].size()) {
				bool ver2 = false;
				for(jt = palabras.begin(); jt != palabras.end(); ++jt) if((*jt) == diccionario[i]) ver2 = true;
				if(!ver2) {
					++suma;
					temp2 = diccionario[i];
					temp2 += to_string(k);
					palabras.insert(temp2);
					++k;
				}
			}
		}

		printf("%d\n", suma);
		palabras.clear();
		scanf("%c", &temp);
	}
	
	return 0;
}