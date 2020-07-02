#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int g[27][27];
bool visited[27];
int c[27];
const int maxn = 27;
int village;
const int INT_MAX=2147483647;

int Prim(int start) {
	fill(visited, visited + 27, false);
	fill(c, c + 27, INT_MAX);
	c[start] = 0;
	while (1) {
		int index = -1, minC = INT_MAX;
		for (int i = 0; i < maxn; i++) {
			if (!visited[i] && c[i] < minC) {
				index = i;
				minC = c[i];
			}
		}
		if (index == -1)
			break;
		visited[index] = true;
		for (int i = 0; i < maxn; i++) {
			if (visited[i]) {
				for (int j = 0; j < maxn; j++) {
					if (!visited[j] && g[i][j] < c[j])
						c[j] = g[i][j];
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < village; i++)
		sum += c[i];
	return sum;
}

int main() {
	while (1) {
		cin >> village;
		if (village == 0)
			break;
		for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 27; j++) {
				if (i == j)
					g[i][j] = 0;
				else
					g[i][j] = INT_MAX;
			}
		}
		char curr, neighbor;
		int count, cost;
		for (int k = 0; k < village - 1; k++) {
			cin >> curr >> count;
			for (int i = 0; i < count; i++) {
				cin >> neighbor >> cost;
				g[curr - 'A'][neighbor - 'A'] = cost;
				g[neighbor - 'A'][curr - 'A'] = cost;
			}
		}
		int minCost = Prim(0);
		cout << minCost << endl;
	}
	return 0;
}
