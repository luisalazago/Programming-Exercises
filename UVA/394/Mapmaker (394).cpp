#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int number_arrays, number_references;
    int base_address, size_elements, number_dimensions;
    int number1, number2;
    int suma1, suma2, suma_total;
    string word;
    vector<int> vector_temp, suma_temp;
    vector<vector<int>> vector_temp2;
    map<string, vector<int>> base_values;
    map<string, vector<vector<int>>> pairs_values;

    cin >> number_arrays >> number_references;
    for(int i = 0; i < number_arrays; ++i) {
        cin >> word >> base_address >> size_elements >> number_dimensions;
        vector_temp.push_back(base_address);
        vector_temp.push_back(size_elements);
        vector_temp.push_back(number_dimensions);
        base_values[word] = vector_temp;
        vector_temp = vector<int>();
        for(int j = 0; j < number_dimensions; ++j) {
            cin >> number1 >> number2;
            vector_temp.push_back(number1);
            vector_temp.push_back(number2);
            if(pairs_values[word].empty()) {
                vector_temp2.push_back(vector_temp);
                pairs_values[word] = vector_temp2;
                vector_temp2 = vector<vector<int>>();
            }
            else pairs_values[word].push_back(vector_temp);
            vector_temp = vector<int>();
        }
    }

    for(int i = 0; i < number_references; ++i) {
        cin >> word;
        for(int j = 0; j < base_values[word][2]; ++j) {
            cin >> number1;
            vector_temp.push_back(number1);
        }

        suma_total = suma1 = suma2 = 0;
        size_elements = base_values[word][1];
        suma_temp.push_back(size_elements);
        for(int j = pairs_values[word].size() - 1; j > 0; --j) {
            number1 = pairs_values[word][j][0];
            number2 = pairs_values[word][j][1];
            suma1 = size_elements * (number2 - number1 + 1);
            size_elements = suma1;
            suma_temp.push_back(suma1);
        }
        
        suma2 = base_values[word][0];
        size_elements = base_values[word][1];
        for(int j = pairs_values[word].size() - 1, k = 0; j >= 0; --j, ++k) {
            suma2 -= suma_temp[j] * pairs_values[word][k][0];
        }
        suma_temp.push_back(suma2);
        

        suma_total = suma_temp[suma_temp.size() - 1];
        for(int j = suma_temp.size() - 2, k = 0; j >= 0; --j, ++k) {
            suma_total += suma_temp[j] * vector_temp[k];
        }

        cout << word << "[";
        for(int j = 0; j < vector_temp.size(); ++j) {
            if(j != vector_temp.size() - 1) cout << vector_temp[j] << ", ";
            else cout << vector_temp[j] << "] = ";
        }
        cout << suma_total << endl;
        vector_temp = suma_temp = vector<int>();
    }

    return 0;
}