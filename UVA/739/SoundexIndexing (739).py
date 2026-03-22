import sys

never_encoded = ["A", "E", "I", "O", "U", "Y", "W", "H"]
encoded = {
    "B": 1, "P": 1, "F": 1, "V": 1,
    "C": 2, "S": 2, "K": 2, "G": 2, "J": 2, "Q": 2, "X": 2, "Z": 2,
    "D": 3, "T": 3,
    "L": 4,
    "M": 5, "N": 5,
    "R": 6
}

def main():
    lines_to_print = []
    for line in sys.stdin:
        word = line.strip()
        if not word:
            continue
        soundex_code = ""
        soundex_code += word[0]
        print_line = "         "
        
        if(len(word) == 1):
            soundex_code += "000"
        else:
            i = 1
            while(i < len(word)):
                if(word[i - 1] in encoded and word[i] in encoded and encoded[word[i]] != encoded[word[i - 1]]):
                    soundex_code += str(encoded[word[i]])
                elif(word[i - 1] not in encoded and word[i] in encoded):
                    soundex_code += str(encoded[word[i]])
                i += 1
            
            while(len(soundex_code) < 4):
                soundex_code += "0"
        
        print_line += word
        for j in range((35 - len(print_line)) - 1):
            print_line += " "
        print_line += soundex_code[0:4]
        lines_to_print.append(print_line)
        
    print("         NAME                     SOUNDEX CODE")
    for line in lines_to_print:
        print(line)
    print("                   END OF OUTPUT")
    
main()