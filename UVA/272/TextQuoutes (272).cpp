#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int ver = 0;
	char temp[3];

	while(scanf("%c", temp) != EOF) {
		if(temp[0] == '\"' && ver == 0) {
			printf("``");
			ver = 1;
		}
		else if(temp[0] == '\"' && ver == 1) {
			printf("''");
			ver = 0;
		}
		else printf("%c", temp[0]);
	}
	return 0;
}