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
//#define INT_MAX 2147483647
using namespace std;

bool available[27] = { false };
int len = 0;
int target;
vector<int> ans;

bool DFS(int d) {
	if (d == 5) {
		if (ans[0] - pow(ans[1], 2) + pow(ans[2], 3) - pow(ans[3], 4) + pow(ans[4], 5) == target)
			return true;
		else
			return false;
	}
	for (int i = 26; i >= 1; i--) {
		if (available[i]) {
			available[i] = false;
			ans.push_back(i);
			if (DFS(d + 1))
				return true;
			else
				ans.pop_back();
			available[i] = true;
		}
	}
}

int main() {
	string strs;
	while (1) {
		cin >> target >> strs;
		if (target == 0 && strs == "END")
			break;
		len = strs.size();
		for (int i = 0; i < 27; i++) {
			available[i] = false;
		}
		ans.clear();
		for (int i = 0; i < len; i++) {
			available[strs[i] - 'A' + 1] = true;
		}
		if (DFS(0)) {
			for (int i = 0; i < 5; i++) {
				char c = (ans[i] - 1) + 'A';
				cout << c;
			}
			cout << endl;
		}
		else {
			cout << "no solution\n";
		}
	}
	return 0;
}
