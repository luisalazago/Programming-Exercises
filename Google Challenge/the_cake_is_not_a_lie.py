def solution(s):
    temp = ""
    ans = None
    for i in range(len(s)):
        temp += s[i]
        if(s.count(temp) * (i + 1) == len(s)):
            ans = s.count(temp)
            break
    return ans
print(solution("abccbaabccba"))
