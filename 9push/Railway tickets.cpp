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

const int Max_l = 10002;
const int inf = 1 << 30;
int dist[Max_l];//dist[i] 表示车站i 与i - 1的距离
int d[Max_l];
int dp[Max_l];
int main() {
    int L1, L2, L3, C1, C2, C3, n, m, from, to, i, j, k;
    while (cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3) {
        cin >> n >> from >> to;
        if (from > to) swap(from, to);
        dist[1] = 0;
        d[1] = 0;
        for (i = 2; i <= n; i++) {
            scanf("%d", &d[i]);
            dist[i] = d[i] - d[i - 1];
        }
        for (i = 0; i <= n; i++)
            dp[i] = inf;
        dp[from] = 0;
        for (i = from + 1; i <= to; i++) {
            int s = dist[i];
            for (j = i - 1; s <= L3 && j >= from; s += dist[j], j--) {//如果从j 到 i
                if (0 < s && s <= L1) m = C1;
                if (L1 < s && s <= L2) m = C2;
                if (L2 < s && s <= L3) m = C3;
                dp[i] = min(dp[i], dp[j] + m);
            }
        }
        cout << dp[to] << endl;
    }
    return  0;
}
