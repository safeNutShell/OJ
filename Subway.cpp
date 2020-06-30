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
//#define INT_MAX 2147483647
using namespace std;

const int N = 300;
const int INF = 9999999;
struct node {
	int x, y;
}q[10000];
double mp[N][N];
bool visited[N];
double Distance[N];
int n, m;

void Dijkstra(int start) {
	memset(visited, false, sizeof(visited));
	fill(Distance, Distance + N, INF);
	Distance[start] = 0;
	while (1) {
		int index = -1;
		double d = INF;
		for (int i = 0; i < N; i++) {
			if (visited[i] == false && Distance[i] < d) {
				index = i;
				d = Distance[i];
			}
		}
		if (index == -1)
			break;
		visited[index] = true;
		for (int i = 0; i < N; i++) {
			if (visited[i] == false) {
				if (Distance[index] + mp[index][i] < Distance[i])
					Distance[i] = Distance[index] + mp[index][i];
			}
		}
	}
}


int main() {
	cin >> q[0].x >> q[0].y >> q[1].x >> q[1].y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				mp[i][j] = 0;
			else
				mp[i][j] = INF;
		}
	}
	m = n = 2;
	while (cin >> q[n].x >> q[n].y) {
		if (q[n].x == -1 && q[n].y == -1) {
			m = n;
			continue;
		}
		if (n != m) {
			double d = sqrt(((double)q[n].x - q[n - 1].x) * ((double)q[n].x - q[n - 1].x) + ((double)q[n].y - q[n - 1].y) * ((double)q[n].y - q[n - 1].y));
			d = d * 3 / 2000;
			mp[n][n - 1] = d;
			mp[n - 1][n] = d;
		}
		n++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mp[i][j] == INF) {
				double d = sqrt(((double)q[j].x - q[i].x) * ((double)q[j].x - q[i].x) + ((double)q[j].y - q[i].y) * ((double)q[j].y - q[i].y));
				d = d * 3 / 500;
				mp[i][j] = d;
				mp[j][i] = d;
			}
		}
	}
	Dijkstra(0);

	printf("%.0f", Distance[1]);
	return 0;
}
