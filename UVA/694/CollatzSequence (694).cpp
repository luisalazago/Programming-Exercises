#include <iostream>

using namespace std;

int main() {
	int ver, terminos, i;
	long long a, limit, secuencia;

	cin >> a >> limit;
	i = 1;
	while(a >= 0 && limit >= 0) {
		ver = 0;
		secuencia = a;
		terminos = 1;
		while(ver != 1) {
			if(secuencia == 1) ver = 1;
			else if(secuencia % 2 == 0) {
				secuencia = secuencia / 2;
				terminos++;
				if(secuencia > limit) {
					secuencia = 1;
					terminos--;
				}
			}
			else if(secuencia % 2 != 0) {
				secuencia = (secuencia * 3) + 1;
				terminos++;
				if(secuencia > limit) {
					secuencia = 1;
					terminos--;
				}
			}
		}
		cout << "Case " << i << ": A = " << a;
		cout << ", limit = " << limit << ", ";
		cout << "number of terms = " << terminos << endl;
		i++;
		cin >> a >> limit; 
	}
	return 0;
}

/*La complejidad de este algoritmo es O(n), ya que evalua todos los casos posibles
  hasta el límite indicado, por eso UVA lo acepta ya que la cantidad de problemas por
  la complejidad no supera el 10^9 que es hasta donde permite UVA.*/