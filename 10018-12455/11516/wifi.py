"""
Nombre: Luis Alberto Salazar.
Código: 8950100.
Complejidad Temporal: O(n*log(n)), ya que lo más complejo que se hace en cuanto tiempo es el
					  ordenamiento del arreglo de casas disponibles para conectar, porque la
					  búsqueda es log(n), entonces esta complejidad acota todas las operaciones
					  realizadas.
Complejidad Espacial: O(n), ya que se crea una lista con todas las casas basadas en available[m - 1],
					  porque en esa posición está la casa más grande que hay.
"""

from sys import stdin

available = []

def aprox(num):
	num *= 100
	num += 0.5
	num = num // 1
	return num / 100

def dispo_usados(mid, n):
	global available
	suma = 1
	router_izq = mid + available[0]
	router_der = router_izq + mid
	flag = True
	for i in range(len(available)):
		if(router_der < available[i]):
			suma += 1
			router_izq = available[i] + mid
			router_der = router_izq + mid
	return suma

def wifi(n, m):
	cant, mid = None, None
	l, h = 0, m
	while(l + 1 < h):
		mid = l + ((h - l) >> 1)
		cant = dispo_usados(mid, n)
		if(cant <= n): l, h = l, mid
		else: l, h = mid, h
	mid = (l + h) / 2
	cant = dispo_usados(mid, n)
	if(cant <= n): l, h = l, mid
	else: l, h = mid, h
	return h


def main():
	global available
	ans = None
	cases = int(stdin.readline())
	i = 0
	while(i < cases):
		n, m = stdin.readline().split()
		n = int(n)
		m = int(m)
		available = []
		for j in range(m): available.append(int(stdin.readline()))
		if(n >= m): ans = 0.0
		else:
			available.sort()
			ans = wifi(n, available[-1])
			ans = aprox(ans)
		print("{:.1f}".format(ans))
		i += 1

main()
