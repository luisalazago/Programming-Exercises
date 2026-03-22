from sys import stdin

words_value = {
    "a": 1, "b": 2, "c": 3, "d": 4, "e": 5, "f": 6, "g": 7, "h": 8, "i": 9,
    "j": 10, "k": 11, "l": 12, "m": 13, "n": 14, "o": 15, "p": 16, "q": 17,
    "r": 18, "s": 19, "t": 20, "u": 21, "v": 22, "w": 23, "x": 24, "y": 25,
    "z": 26
}

def main():
    lines = iter(stdin.read().splitlines())
    for word in lines:
        try:
            word2 = next(lines)
        except StopIteration:
            break

        word = word.lower()
        word2 = word2.lower()
        
        result = 0
        for car in word:
            if car in words_value:
                result += words_value[car]
        
        result2 = 0
        for car in word2:
            if car in words_value:
                result2 += words_value[car]

        result = str(result)
        result2 = str(result2)
        
        while len(result) > 1:
            temp = sum(int(i) for i in result)
            result = str(temp)
        
        while len(result2) > 1:
            temp = sum(int(i) for i in result2)
            result2 = str(temp)

        result = int(result)
        result2 = int(result2)
        percentage = (min(result, result2) / max(result, result2)) * 100
        print("{:.2f} %".format(percentage))

main()