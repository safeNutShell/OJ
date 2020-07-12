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
	cin >> n;
	int** image = new int* [n];
	for (int i = 0; i < n; i++)image[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> image[i][j];
	int area = 0, c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (image[i][j] <= 50) {
				area++;
				bool edge = false;
				if (j + 1 < n && image[i][j + 1] > 50 || j + 1 == n)
					edge = true;
				else if (i + 1 < n && image[i + 1][j] > 50 || i + 1 == n)
					edge = true;
				else if (j - 1 >= 0 && image[i][j - 1] > 50 || j == 0)
					edge = true;
				else if (i - 1 >= 0 && image[i - 1][j] > 50 || i == 0)
					edge = true;
				if (edge)
					c++;
			}
		}
	}
	cout << area << ' ' << c << endl;
	delete[] image;
	return 0;
}
