#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define INFINITO 2000000
#define endl '\n'

using namespace std;

bool compare(pair<string, pair<int, int>> w1, pair<string, pair<int, int>> w2) {
	return w1.second.first < w2.second.first;
}

void sort_words(vector<pair<string, pair<int, int>>>& words, int& cant_words) {
	pair<string, pair<int, int>> temp;

	for(int i = 0; i < cant_words - 1; ++i) {
		for(int j = i + 1; j < cant_words; ++j) {
			if(words[j].second.first == words[i].second.first) {
				if(words[j].second.second < words[i].second.second) {
					temp = words[i];
					words[i] = words[j];
					words[j] = temp;
				}
			}
		}
	}
}

int main() {
	string word;
	int cases, length, cant_words, count;
	pair<int, int> temp2;
	pair<string, pair<int, int>> temp;
	vector<pair<string, pair<int, int>>> words;

	cin >> cases;
	while(cases--) {
		cin >> length >> cant_words;
		for(int i = 0; i < cant_words; ++i) {
			cin >> word;
			temp.first = word;
			count = 0;
			for(int j = 0; j < length - 1; ++j) {
				for(int k = j + 1; k < length; ++k) {
					if(word[j] > word[k] && k != j) ++count;
				}
			}
			temp2.first = count;
			temp2.second = i;
			temp.second = temp2;
			words.push_back(temp);
		}

		sort(words.begin(), words.end(), compare);

		sort_words(words, cant_words);

		for(int i = 0; i < cant_words; ++i) cout << words[i].first << endl;
		if(cases) cout << endl;

		words = vector<pair<string, pair<int, int>>>();
	}
	
	return 0;
}