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

char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int main() {
	string cipher, plain = "";
	getline(cin, cipher);
	for (int i = 0; i < cipher.size(); i++) {
		char c = (char)cipher[i];
		if (isupper(c)) {
			int cur = c - 'A';
			int re = (cur + 21) % 26;
			plain += alphabet[re];
		}
		else {
			plain += (char)cipher[i];
		}
	}
	cout << plain << endl;
	return 0;
}
