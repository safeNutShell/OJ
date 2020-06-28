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
int n, a, b;
const int maxn = 110;
bool visited[maxn];
int Distance[maxn];
int mp[maxn][maxn];
  
void Dijkstra(int start) {
	for (int i = 0; i < maxn; i++) visited[i] = false;
	for (int i = 0; i < maxn; i++) Distance[i] = INT_MAX;
	Distance[start] = 0;
	while (1) {
		int minD = INT_MAX, index = -1;
		for (int i = 1; i <= n; i++) {
			if (Distance[i] < minD && visited[i] == false) {
				index = i;
				minD = Distance[i];
			}
		}
		if (index == -1)
			return;
		visited[index] = true;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false && mp[index][i] != INT_MAX) {
				if (Distance[index] + mp[index][i] < Distance[i]) {
					Distance[i] = Distance[index] + mp[index][i];
				}
			}
		}
	}
}

int main() {
	cin >> n >> a >> b;
	if (a == b) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++) {
			if (i == j)
				mp[i][j] = 0;
			else
				mp[i][j] = INT_MAX;
		}
	for (int i = 1; i <= n; i++) {
		int num;
		int tmp;
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> tmp;
			if (j == 0)
				mp[i][tmp] = 0;
			else
				mp[i][tmp] = 1;
		}
	}
	Dijkstra(a);
	if (visited[b] == false) 
		cout << -1 << endl;
	else
		cout << Distance[b] << endl;
	return 0;
}
