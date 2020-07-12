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

//不能用99999999，真的有测试用例票价比这个高……
//确认没有加减法运算时还是用INT_MAX吧
//const int inf = 99999999;

int main() {
	int l1, l2, l3, c1, c2, c3;
	while (cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3) {
		int n, start, end;
		cin >> n >> start >> end;
		if (start > end)
			swap(start, end);
		int dis[10010];
		int dp[10010];
		dis[0] = 0;
		dis[1] = 0;
		for (int i = 2; i < n + 1; i++)
			cin >> dis[i];
		for (int i = 0; i < n + 1; i++) {
			if (i <= start)
				dp[i] = 0;
			else
				dp[i] = INT_MAX;
		}
		for (int i = start + 1; i <= end; i++) {
			for (int j = i - 1; j >= start; j--) {
				int d = dis[i] - dis[j];
				if (d > l3)
					break;
				int cost = 0;
				if (d > 0 && d <= l1)
					cost = c1;
				else if (d > l1&& d <= l2)
					cost = c2;
				else if (d > l2&& d <= l3)
					cost = c3;
				dp[i] = min(dp[i], cost + dp[j]);
			}
		}
		cout << dp[end] << endl;
	}
	return 0;
}
