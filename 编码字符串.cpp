#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<map>
#include<vector>
//#define INT_MAX 2147483647
using namespace std;

int main() {
	string str;
	cin >> str;
	int thisCount = 1;
	char thisChar;
	char lastChar;
	if (str[0] >= 'A' && str[0] <= 'Z') {
		int delta = str[0] - 'A';
		thisChar = 'a' + delta;
	}
	else {
		thisChar = str[0];
	}
	if (str.length() == 1) {
		cout << "(" << thisChar << "," << thisCount << ")" << endl;
	}
	for (int i = 1; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int delta = str[i] - 'A';
			lastChar = thisChar;
			thisChar = 'a' + delta;
		}
		else {
			lastChar = thisChar;
			thisChar = str[i];
		}
		if (lastChar == thisChar) {
			thisCount++;
			if (i == str.length() - 1) {
				cout << "(" << thisChar << "," << thisCount << ")";
			}
		}
		else {
			cout << "(" << lastChar << "," << thisCount << ")";
			thisCount = 1;
			if(i==str.length()-1)
				cout << "(" << thisChar << "," << thisCount << ")";
		}
	}
	return 0;
}
