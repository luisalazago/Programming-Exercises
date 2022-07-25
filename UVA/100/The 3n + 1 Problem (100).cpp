#include <iostream>

#define INFINITO 2000000
#define endl '\n'

using namespace std;

int main() {
	int num1, num2, n, temp, count, max, b;

	while(cin >> num1 >> num2) {
		if(num1 > num2) {
			b = num1;
			n = num2;
		}
		else {
			b = num2;
			n = num1;
		}
		max = -9999;
		while(n <= b) {
			temp = n;
			count = 1;
			while(temp > 1) {
				if(temp % 2 == 0) temp = temp / 2;
				else temp = (3 * temp) + 1;
				++count;
			}
			if(count > max) max = count;
			++n;
		}

		cout << num1 << " " << num2 << " " << max << endl;
	}
	return 0;
}