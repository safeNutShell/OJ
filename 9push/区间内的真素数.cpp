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

bool isPrime(int a) {
	if (a < 2) return false;
	int bound = (int)sqrt(a) + 1;
	for (int i = 2; i <= bound; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}

int RE(int a) {
	string tmp = to_string(a);
	reverse(tmp.begin(), tmp.end());
	int ans = stoi(tmp);
	return ans;
}

int main() {
	int m, n;
	vector<int> ans;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		int re = RE(i);
		if (isPrime(i) && isPrime(re))
			ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size() - 1)
			cout << ",";
		else
			cout << endl;
	}
	return 0;
}
