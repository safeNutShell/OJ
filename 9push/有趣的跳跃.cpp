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

int main() {
	int n;
	int a[3010], b[3010];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int j = 0;
	for (j; j < n - 1; j++)
		b[j] = abs(a[j] - a[j + 1]);
	sort(b, b + j);
	int k = 0;
	for (k; k < n - 1; k++) {
		if (b[k] != k + 1)
			break;
	}
	if (k == n - 1)
		cout << "Jolly" << endl;
	else
		cout << "Not jolly" << endl;
	return 0;
}
