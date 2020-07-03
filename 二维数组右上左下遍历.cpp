#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int row, column;
	cin >> row >> column;
	int** matrix = new int* [row];
	for (int i = 0; i < row; i++) matrix[i] = new int[column];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			cin >> matrix[i][j];
	int bound = min(row, column);
	for (int i = 0; i < column; i++) {
		int r = 0;
		int c = i;
		for (int count = 0; count < bound && r < row && c >= 0; count++) {
			cout << matrix[r][c] << endl;
			r++;
			c--;
		}
	}
	for (int i = 1; i < row; i++) {
		int r = i;
		int c = column - 1;
		for (int count = 0; count < bound && r < row && c >= 0; count++) {
			cout << matrix[r][c] << endl;
			r++;
			c--;
		}
	}
	delete[]matrix;
	return 0;
}
