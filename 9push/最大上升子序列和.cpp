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
	int n, a;
	cin >> n;
	vector<int>num, dp;
	//int* num = new int[n];
	//int* dp = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a;
		num.push_back(a);
		dp.push_back(a);
	}
	int ans = num[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j])
				dp[i] = max(dp[i], num[i] + dp[j]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
