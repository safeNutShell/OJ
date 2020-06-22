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

bool cmp(string a, string b) {
	return a < b;
}

string func(int a) {
	vector<string> ans;
	for (int i = 1; i <= a; i++) {
		ans.push_back(to_string(i));
	}
	sort(ans.begin(), ans.end(), cmp);
	return ans[ans.size() - 1];
}

int main() {
	int a;
	while (1) {
		cin >> a;
		if (a == 0)
			break;
		cout << func(a) << endl;
	}
	return 0;
}
