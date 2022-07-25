#include <iostream>
#include <vector>

using namespace std;

int main() {
	int courses_chosen, categories, numero;
	int categorie, courses_categorie;
	vector<int> cc;
	vector<int> courses_in_categorie;

	cin >> courses_chosen >> categories;
	while(courses_chosen) {
		for(int i = 0; i < courses_chosen; i++) {
			cin >> numero;
			cc.push_back(numero);
		}

		cin >> categorie >> courses_categorie;
		for(int i = 0; i < categorie; i++) {
			cin >> numero;
			courses_in_categorie.push_back(numero);
		}

		



		cin >> courses_chosen >> categories;
	}

	return 0;
}