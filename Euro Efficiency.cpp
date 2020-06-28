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
#define INT_MAX 2147483647
using namespace std;
const int maxn = 5100;
int dp[maxn];

int main() {
	int n;
	cin >> n;
	int val[10];
	for (int z = 0; z < n; z++) {
		for (int i = 1; i <= 6; i++)
			cin >> val[i];
		dp[0] = 0;
		for (int i = 1; i < maxn; i++)
			dp[i] = INT_MAX;
		for (int i = 1; i <= 6; i++) {
			for (int j = val[i]; j < maxn; j++) {
				if (dp[j - val[i]] != INT_MAX) {
					dp[j] = min(dp[j], dp[j - val[i]] + 1);
				}
			}
		}
		for (int i = 1; i <= 6; i++) {
			for (int j = maxn - val[i]; j >= 0; j--) {
				if (dp[j + val[i]] != INT_MAX) {
					dp[j] = min(dp[j], dp[j + val[i]] + 1);
				}
			}
		}
		int sum = 0, count = -1;
		for (int i = 0; i <= 100; i++) {
			sum += dp[i];
			count = max(count, dp[i]);
		}
		double sumd = (double)sum / 100;
		printf("%.2f %d\n", sumd, count);
	}
	return 0;
}
