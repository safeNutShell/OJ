#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
//#define INT_MAX 2147483647

using namespace std;

int main() {
	string isbn;
	cin >> isbn;
	int sum = 0;
	int mul = 1;
	for (int i = 0; i < 11; i++) {
		if (i == 1 || i == 5)
			continue;
		else {
			char tmp = isbn[i];
			sum += (tmp - '0') * mul;
			mul++;
		}
	}
	int code = sum % 11;
	char test;
	if (code == 10) {
		test = 'X';
	}
	else {
		test = code + '0';
	}
	if (test == isbn[12])
		cout << "Right" << endl;
	else {
		isbn[12] = test;
		cout << isbn << endl;
	}
	return 0;
}
