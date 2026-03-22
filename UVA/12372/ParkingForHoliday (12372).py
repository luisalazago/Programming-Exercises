from sys import stdin

def main():
    cases = int(stdin.readline())
    i = 0
    while(i < cases):
        length, width, height = stdin.readline().split()
        length = int(length)
        width = int(width)
        height = int(height)
        answer = False
        if(length <= 20 and width <= 20 and height <= 20):
            answer = True
        if(answer == True):
            print("Case {}: good".format(i + 1))
        else:
            print("Case {}: bad".format(i + 1))
        i += 1

main()