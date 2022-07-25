from sys import stdin

pesos = []
mem = {}

def monda(n, x):
	global mem
	ans = None
	if((n, x) in mem): ans = mem[(n, x)]
	else:
		if not n and not x: ans = True
		elif not n and x != 0: ans = False
		elif(n != 0):
			if(x < pesos[n - 1]): ans = monda(n - 1, x)
			else: ans = monda(n - 1, x) or monda(n - 1, x - pesos[n - 1])
		mem[(n, x)] = ans
	return ans

def main():
	global pesos, mem
	ans = None
	casos = int(stdin.readline())
	for i in range(casos):
		lectura = stdin.readline()
		pesos = []
		mem = {}
		j, suma = 0, 0
		temp = ""
		while(j < len(lectura)):
			if(lectura[j] != " " and lectura[j] != "\n"): temp += lectura[j]
			else:
				pesos.append(int(temp))
				suma += int(temp)
				temp = ""
			j += 1

		if(suma % 2 != 0): ans = False
		else: ans = monda(len(pesos), suma // 2)

		if(ans): print("YES")
		else: print("NO")
main()