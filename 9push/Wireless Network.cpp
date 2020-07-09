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

struct computer {
	int x, y;
}mp[1010];
int Tree[1010];
bool vis[1010];

int findRoot(int x) {
	int a = x;
	while (Tree[x] != x) {
		x = Tree[x];
	}
	while (Tree[a] != a) {
		int tmp = a;
		a = Tree[a];
		Tree[tmp] = x;
	}
	return x;
}

void Union(int a, int b) {
	int a1 = findRoot(a);
	int b1 = findRoot(b);
	if (a1 != b1) {
		Tree[b1] = a1;
	}
}

double calDis(computer a, computer b) {
	return sqrt((double)pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main() {
	int n;
	double d;
	cin >> n >> d;
	int x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		computer pc;
		pc.x = x;
		pc.y = y;
		mp[i] = pc;
	}
	for (int i = 0; i < 1010; i++) Tree[i] = i;
	fill(vis, vis + 1010, false);
	char ope;
	int para1, para2;
	while (cin >> ope) {
		if (ope == 'O') {
			cin >> para1;
			if (vis[para1]) continue;
			vis[para1] = true;
			for (int i = 1; i <= n; i++) {
				if (i != para1 && vis[i]) {
					double dis = calDis(mp[i], mp[para1]);
					if (dis <= d) {
						Union(para1, i);
					}
				}
			}
		}
		else {
			cin >> para1 >> para2;
			int fa1 = findRoot(para1);
			int fa2 = findRoot(para2);
			if (fa1 == fa2)
				cout << "SUCCESS" << endl;
			else
				cout << "FAIL" << endl;
		}
	}
	return 0;
}
