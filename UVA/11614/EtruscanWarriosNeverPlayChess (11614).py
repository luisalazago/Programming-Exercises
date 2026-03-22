from sys import stdin
from math import sqrt

def main():
    """
    Correct answer but reach time limit.
    """
    cases = int(stdin.readline())
    for i in range(cases):
        n = int(stdin.readline()) # n es el numero de guerreros que queremos encontrar.
        warriors_before = 0
        rows_before = 0
        answer_before = 0
        warriors = 1
        rows = 1
        answer = 1
        if(n == 0):
            print(0)
        else:
            if(i > 0 and n >= warriors):
                warriors = warriors_before
                rows = rows_before
                answer = answer_before
            while(warriors != n):
                if(n >= warriors and n < warriors + (rows + 1)):
                    answer = rows
                    warriors = n
                elif(n == warriors + (rows + 1)):
                    answer = rows + 1
                    warriors = n
                else:
                    rows += 1
                    warriors += rows
            print(answer)
            warriors_before = warriors
            rows_before = rows
            answer_before = answer

def main2():
    cases = int(stdin.readline())
    for i in range(cases):
        n = int(stdin.readline())
        rows = 0
        if(n > 0):
            rows = int((-1 + sqrt(1 + 8 * n)) / 2) # This is found by the quadratic formula.
        print(rows)

#main()
main2()