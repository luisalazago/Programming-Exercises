#include <iostream>
#include <string>
#include <set>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

set<string> palabras;
set<string>::iterator it;
string temp;

int revisada1(string& palabra, int& pos) {
	int ver, i, j;
	i = ver = 0;
	j = pos;
	temp = "";
	while(i < pos + 1 && j >= 0) {
		if(palabra[i] == palabra[j]) {
			++ver;
			temp += palabra[i];
		}
		else {
			ver = 0;
			temp = "";
			break;
		}
		++i;
		--j;
	}
	return ver;
}

int revisada2(string& palabra, int& pos) {
	int ver, i, j, pos2, pos3;
	i = (palabra.size() - 1) - pos;
	j = (palabra.size() - 1) - i;
	ver = 0;
	pos2 = i;
	pos3 = j + 1;
	temp = "";
	while(i < pos3 && j >= pos2) {
		if(palabra[i] == palabra[j]) {
			++ver;
			temp += palabra[i];
		}
		else {
			ver = 0;
			temp = "";
			break;
		}
		++i;
		--j;
	}
	return ver;
}

int revisada3(string& palabra, int& pos) {
	int i, j, ver, pos2;
	i = (palabra.size() - 1) - pos;
	j = (palabra.size() - 1);
	ver = 0;
	pos2 = i;
	temp = "";
	while(i < palabra.size() && j >= pos2) {
		if(palabra[i] == palabra[j]) {
			++ver;
			temp += palabra[i];
		}
		else {
			ver = 0;
			temp = "";
			break;
		}
		++i;
		--j;
	}
	return ver;
}

int main() {
	FAST_IO;
	int cant_palindromes, pos, ver, pos2;
	string palabra;

	while(cin >> palabra) {
		cant_palindromes = 0;
		pos = palabra.size() - 1;

		for(int i = 0; i < palabra.size(); ++i) {
			ver = 0;
			temp = palabra[i];
			for(it = palabras.begin(); it != palabras.end(); ++it) if((*it) == temp) ver = 1;
			if(!ver) {
				palabras.insert(temp);
				++cant_palindromes;
			}
		}

		while(pos > 0) {
			ver = revisada1(palabra, pos);
			if(ver) {
				++cant_palindromes;
				for(it = palabras.begin(); it != palabras.end(); ++it) if((*it) == temp) --cant_palindromes;
			}
			if(temp != "") palabras.insert(temp);

			ver = revisada2(palabra, pos);
			if(ver) {
				++cant_palindromes;
				for(it = palabras.begin(); it != palabras.end(); ++it) if((*it) == temp) --cant_palindromes;
			}
			if(temp != "") palabras.insert(temp);

			ver = revisada3(palabra, pos);
			if(ver) {
				++cant_palindromes;
				for(it = palabras.begin(); it != palabras.end(); ++it) if((*it) == temp) --cant_palindromes;
			}
			if(temp != "") palabras.insert(temp);

			--pos;
		}	

		
		for(int i = 0; i < palabra.size(); ++i) {
			ver = 0;
			pos = palabra.size();
			pos2 = i;
			while(pos - 1 > i) {
				temp = "";
				for(int j = pos - 1; j >= i && pos2 < pos; --j, ++pos2) {
					if(palabra[pos2] == palabra[j]) {
						++ver;
						temp += palabra[pos2];
					}
					else {
						ver = 0;
						temp = "";
						break;
					}
				}
				pos2 = i;
				--pos;
				if(ver) {
					++cant_palindromes;
					for(it = palabras.begin(); it != palabras.end(); ++it) if((*it) == temp) --cant_palindromes;
				}
				if(temp != "") palabras.insert(temp);
			}
		}

		cout << "The string '" << palabra << "' contains " << cant_palindromes << " palindromes." << endl;
		palabras.clear();
	}
	return 0;
}