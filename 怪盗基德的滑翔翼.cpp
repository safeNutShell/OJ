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
//#define INT_MAX 2147483647
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int count;
		cin >> count;
		int* val = new int[count];
		int* dp = new int[count];
		for (int i = 0; i < count; i++)
			cin >> val[i];
		int max1 = 0, max2 = 0;
		for (int i = 0; i < count; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (val[j] > val[i] && dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
			max1 = max(max1, dp[i]);
		}
		for (int i = count - 1; i >= 0; i--) {
			dp[i] = 1;
			for (int j = count - 1; j > i; j--) {
				if (val[j] > val[i] && dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
			max2 = max(max2, dp[i]);
		}
		int ans = max(max1, max2);
		cout << ans << endl;
	}
	return 0;
}
