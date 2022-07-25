#include <iostream>
#include <vector>

using namespace std; 

int main() {
	int books, libro, precio, minimo, temp_minimo, ver;
	vector<int> precios_libros;
	vector<int> pareja;
	vector<int> temp;
	vector<int> temp2;
	vector<int> minimoR;
	vector< vector<int> > resultados;
	
	while(cin >> books) {
		cin.ignore();
		for(int i = 0; i < books; i++) {
			cin >> libro;
			precios_libros.push_back(libro);
		}

		cin >> precio;

		for(int i = 0; i < precios_libros.size(); i++) {
			for(int j = 0; j < books; j++) {
				if(precios_libros[j] > precios_libros[i]) {
					minimo = precios_libros[i];
					precios_libros[i] = precios_libros[j];
					precios_libros[j] = minimo;
				}
			}
		}

		for(int i = 0; i < precios_libros.size(); i++) temp.push_back(precios_libros[i]);
	
		for(int i = 0; i < books; i++) {
			if(precios_libros[i] <= precio) {
				pareja.push_back(precios_libros[i]);
				int j = (temp.size() / 2) - 1;
				while(j < temp.size()) {
					if(temp[j] + precios_libros[i] == precio) {
						pareja.push_back(temp[j]);
						break;
					}
					else if(temp[j] >= precios_libros[i] || temp[j] < precios_libros[i]) {
						if(temp[j] + precios_libros[i] < precio) {
							for(int k = j + 1; k < temp.size(); k++) temp2.push_back(temp[k]);
							temp.clear();
							for(int k = 0; k < temp2.size(); k++) temp.push_back(temp2[k]);
							temp2.clear();
						}
						else if(temp[j] + precios_libros[i] > precio) {
							if(temp.size() == 1) break;
							for(int k = 0; k <= j; k++) temp2.push_back(temp[k]);
							temp.clear();
							for(int k = 0; k < temp2.size(); k++) temp.push_back(temp2[k]);
							temp2.clear();
						}
					}
					j = (temp.size() / 2) - 1;
					if(j == -1) j = 0;
				}
				if(pareja.size() > 1) resultados.push_back(pareja);
				pareja.clear();
				temp.clear();
				for(int j = 0; j < precios_libros.size(); j++) temp.push_back(precios_libros[j]);
			}
		}

		minimo = 50000001;
		for(int i = 0; i < resultados.size(); i++) {
			temp_minimo = resultados[i][1];
			temp_minimo -= resultados[i][0];
			if(temp_minimo >= 0) {
				ver = 0;
				if(resultados[i][0] == resultados[i][1]) 
					for(int j = 0; j < precios_libros.size(); j++) if(precios_libros[j] == resultados[i][0]) ver++;
				if(ver >= 2 || resultados[i][0] != resultados[i][1]) {
					if(temp_minimo < minimo) {
						minimo = temp_minimo;
						minimoR.clear();
						minimoR.push_back(resultados[i][0]);
						minimoR.push_back(resultados[i][1]);
					}
				}
			}
		}

		cout << "Peter should buy books whose prices are " << minimoR[0] << " and " << minimoR[1] << "." << endl;
		cout << endl;
		precios_libros.clear();
		temp.clear();
		temp2.clear();
		pareja.clear();
		minimoR.clear();
		resultados.clear();
	}
	return 0;
}