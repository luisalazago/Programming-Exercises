#include <iostream>
#include <utility>
#include <cstdlib>

#define INFINITO 2000000
#define endl '\n'

using namespace std;

int main() {
	int coordinates;
	pair<int, int> point_division, point;

	cin >> coordinates;
	while(coordinates) {
		cin >> point_division.first >> point_division.second;
		for(int i = 0; i < coordinates; ++i) {
			cin >> point.first >> point.second;
			if(point.first == point_division.first || point.second == point_division.second) {
				cout << "divisa" << endl;
			}
			else if(point.first > point_division.first && point.second > point_division.second) {
				cout << "NE" << endl;
			}
			else if(point.first > point_division.first && point.second < point_division.second) {
				cout << "SE" << endl; 
			}
			else if(point.first < point_division.first && point.second > point_division.second) {
				cout << "NO" << endl;
			}
			else cout << "SO" << endl;
		}

		cin >> coordinates;
	}
	return 0;
}