def cs(flag):
    if(flag): return (False, 1)
    return (True, -1)

def solution(pegs):
    menor = -2**32
    flag = False
    sign = 1
    ans = []
    d = []
    i = len(pegs) - 1
    while(i > 0):
        if(pegs[i] - pegs[i - 1] < menor):
            ans = None
            break
        else:
            menor = pegs[i] - pegs[i - 1]
            d.append(menor * sign)
            flag, sign = cs(flag)
        i -= 1
    if ans != None:
        menor = 0
        if not len(pegs) % 2:
            for i in range(len(d)): menor += d[i]
            menor /= 3
            menor *= 2
        else:
            for i in range(len(d)): menor += (d[i] * -1)
            menor *= 2
        ans = [int(menor), 1]
    else: ans = [-1, -1]
    return ans

print(solution([4, 4, 4, 4]))
