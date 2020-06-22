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

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> step;
	for (int i = 1; i <= k; i++) {
		if (i % 10 == 4 || i / 10 == 4)
			continue;
		else
			step.push_back(i);
	}
	long long int dp[55] = { 0 };
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 0; j < step.size(); j++) {
			if (i - step[j] >= 1) {
				dp[i] += dp[i - step[j]];
			}
			else
				break;
		}
	}
	cout << dp[n + 1] << endl;
}
