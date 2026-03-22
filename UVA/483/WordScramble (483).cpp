#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string line, reverse_line, sentence;

    while(getline(cin, line)) {
        reverse_line = sentence = "";
        for(int i = 0; i < line.size(); ++i) {
            if(line[i] != ' ') sentence += line[i];
            if(line[i] == ' ' || i == line.size() - 1) {
                if(!sentence.empty()) {
                    reverse(sentence.begin(), sentence.end());
                    reverse_line += sentence;
                    sentence = "";
                }
                if(line[i] == ' ') reverse_line += line[i];
            }
        }
        cout << reverse_line << endl;
    }

    return 0;
}