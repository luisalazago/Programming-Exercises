#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

#define INFINITO 2000000
#define endl '\n'

using namespace std;

int main() {
	int filenames, max_length, columns_length, rows_length;
	string word;
	vector<string> temp;

	while(cin >> filenames) {
		temp = vector<string>(filenames);
		max_length = 0;
		for(int i = 0; i < filenames; ++i) {
			cin >> word;
			temp[i] = word;
			max_length = max(max_length, (int)word.length());
		}

		max_length += 2;
		sort(temp.begin(), temp.end());

		if(max_length > 60) max_length = 60;
		columns_length = 62 / max_length;
		rows_length = (filenames - 1) / columns_length + 1;	

		cout << "------------------------------------------------------------" << endl;
		for(int i = 0; i < rows_length; ++i) {
			for(int j = i; j < filenames; j += rows_length) {
				cout << temp[j];
				if(j + rows_length < filenames)
					for(int k = temp[j].length(); k < max_length; ++k) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}