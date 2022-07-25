#include <iostream>

#define INFINITO 2000000
#define endl '\n'

using namespace std;

int main() {
	int nums, max, end, k, numero;

	cin >> nums;
	while(nums) {
		cin.ignore();
		max = INFINITO * -1;
		end = k = 0;
		while(k < nums) {
			cin >> numero;
			end += numero;
			if(max < end) max = end;
			if(end < 0) end = 0;
			++k;
		}

		if(max > 0) cout << "The maximum winning streak is " << max << "." << endl;
		else cout << "Losing streak." << endl; 
		cin >> nums;
	}

	return 0;
}