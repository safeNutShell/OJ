#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

const int maxd = 99999;
int g[21][21];
bool visited[21];
int d[21];

void dijkstra(int start, int end) {
	fill(visited, visited + 21, false);
	fill(d, d + 21, maxd);
	d[start] = 0;
	while (1) {
		int index = -1, minD = maxd;
		for (int i = 1; i < 21; i++) {
			if (visited[i] == false && d[i] < minD) {
				index = i;
				minD = d[i];
			}
		}
		if (index == -1)
			return;
		visited[index] = true;
		if (visited[end] == true)
			return;
		for (int i = 1; i < 21; i++) {
			if (visited[i] == false && d[index] + g[index][i] < d[i]) {
				d[i] = d[index] + g[index][i];
			}
		}
	}
}

int main() {
	int sum, neighbor;
	int test = 1;
	while (cin >> sum) {
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				if (i == j)
					g[i][j] = 0;
				else
					g[i][j] = maxd;
			}
		}
		for (int i = 0; i < sum; i++) {
			cin >> neighbor;
			g[1][neighbor] = 1;
			g[neighbor][1] = 1;
		}
		for (int i = 2; i <= 19; i++) {
			cin >> sum;
			for (int j = 0; j < sum; j++) {
				cin >> neighbor;
				g[i][neighbor] = 1;
				g[neighbor][i] = 1;
			}
		}
		cout << "Test Set #" << test << endl;
		test++;
		int query;
		cin >> query;
		int start, end;
		while (query--) {
			cin >> start >> end;
			dijkstra(start, end);
			cout << start << " to " << end << ": " << d[end] << endl;
		}
		cout << endl;
	}
	return 0;
}
