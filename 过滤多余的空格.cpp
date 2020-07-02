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
	string str, ans;
	getline(cin, str);
	int ptr = 0;
	while (ptr < str.length()) {
		if (str[ptr] != ' ')
			ans += str[ptr++];
		else {
			ans += ' ';
			while (str[ptr] == ' ')ptr++;
		}
	}
	cout << ans << endl;
	return 0;
}
