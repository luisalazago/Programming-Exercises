from sys import stdin

def main():
    equation = str(stdin.readline())
    equation = equation[0:-1]
    while(equation):
        print(equation)
        equation = str(stdin.readline())
        equation = equation[0:-1]

main()