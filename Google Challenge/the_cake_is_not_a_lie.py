def solution(s):
    
    for i in range(1, len(s) + 1):
        temp = s[:i]
        print(temp)
        count = s.count(temp)
        print(count)
        if(count * i == len(s)): return count

print(solution("abcabcabcabc"))
