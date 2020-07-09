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

const int maxn = 40;
int r, c;
int dp[maxn][maxn];
int dis[maxn][maxn];
bool visitef[maxn] = { false };

int stepx[4] = { 0,1,0,-1 };
int stepy[4] = { 1,0,-1,0 };

struct node {
	int x, y;
};

void BFS(int rstart,int cstart) {
	node start;
	start.x = rstart;
	start.y = cstart;
	queue<node>q;
	q.push(start);
	dis[rstart][cstart] = 1;
	dp[rstart][cstart] = 0;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.x + stepx[i];
			int y = cur.y + stepy[i];
			if (x >= 0 && y >= 0 && x < r && y < c && dp[x][y] == 1) {
				dis[x][y] = dis[cur.x][cur.y] + 1;
				dp[x][y] = 0;
				node a;
				a.x = x;
				a.y = y;
				q.push(a);
			}
		}

	}
}


int main() {
	cin >> r >> c;
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			dp[i][j] = 0;
			dis[i][j] = 0;
		}
	}
	string str;
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < c; j++) {
			char a = (char)str[j];
			if (a == '.')
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}
	BFS(0, 0);
	cout << dis[r - 1][c - 1] << endl;
	return 0;
}
