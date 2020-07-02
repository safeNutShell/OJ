#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	int ptr = 0;
	for (int i = 0; i < str.length(); i++) {
		if (i != str.length() - 1 && str[i] == ' ') {
			reverse(str.begin() + ptr, str.begin() + i);
			ptr = i + 1;
		}
		if (i == str.length() - 1) {
			if (str[i] != ' ') {
				reverse(str.begin() + ptr, str.begin() + i + 1);
			}
			else {
				reverse(str.begin() + ptr, str.begin() + i);
			}
		}
	}
	cout << str << endl;
	return 0;
}
