#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
//#define INT_MAX 2147483647

using namespace std;

bool isPalindrome(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int l = 0;
		string ans;
		for (int k = 0; k < str.length(); k++) {
			for (int j = k; j < str.length(); j++) {
				string sub = str.substr(k, j - k + 1);
				if (isPalindrome(sub)) {
					if (sub.length() > l) {
						ans = sub;
						l = sub.length();
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
