#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	int base_data, evaluation, ascii;
	double temp2;
	vector<double> base_valor;
	vector<string> base;
	vector<string> conjeturas;
	vector<double> conjeturas_num;
	string temp, numero;

	cin >> base_data >> evaluation;
	for(int i = 0; i < base_data; i++) {
		cin >> temp >> temp2;
		base.push_back(temp);
		base_valor.push_back(temp2);
	}
	for(int i = 0; i < evaluation; i++) {
		getline(cin, temp);
		numero = "";
		for(int j = 0; j < temp.size(); j++) {
			ascii = temp[i].c_str();
			if(ascii >= 48 && ascii <= 57) numero += temp[i];
		}
		stringstream geek(numero);
		geek >> numero;
		conjeturas_num.push_back(numero);
		
	}

	return 0;
}