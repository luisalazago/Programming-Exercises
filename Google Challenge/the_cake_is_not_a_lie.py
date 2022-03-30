def solution(s):
    temp = ""
    ans = None
    for i in range(len(s)):
        temp += s[i]
        if(s.count(temp) * (i + 1) == len(s)):
            ans = s.count(temp)
            break
    return ans
    """
    for i in range(1, len(s) + 1):
        temp = s[:i]
        print(temp)
        count = s.count(temp)
        print(count)
        if(count * i == len(s)): return count
    """
print(solution("abccbaabccba"))
