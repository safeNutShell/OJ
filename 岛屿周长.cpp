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
	int n, m;
	cin >> n >> m;
	int** mp = new int* [n + 2];
	for (int i = 0; i < n + 2; i++) mp[i] = new int[m + 2];
	for (int i = 0; i < n + 2; i++)
		for (int j = 0; j < m + 2; j++)
			mp[i][j] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
		}
	}
	int C = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mp[i][j] == 1) {
				if (mp[i - 1][j] == 0) C++;
				if (mp[i][j - 1] == 0) C++;
				if (mp[i + 1][j] == 0) C++;
				if (mp[i][j + 1] == 0) C++;
			}
		}
	}
	cout << C << endl;
	return 0;
}
