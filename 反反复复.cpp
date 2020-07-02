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
	int column;
	cin >> column;
	string cipher;
	cin >> cipher;
	char** matrix = new char* [110];
	for (int i = 0; i < 110; i++) matrix[i] = new char[column];
	for (int i = 0; i < 110; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = '.';
	int row = cipher.length() / column;
	int ptr = 0;
	for (int i = 0; i < row; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < column; j++) {
				matrix[i][j] = (char)cipher[ptr];
				ptr++;
			}
		}
		else {
			for (int j = column - 1; j >= 0; j--) {
				matrix[i][j] = (char)cipher[ptr];
				ptr++;
			}
		}
	}
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++)
			cout << matrix[j][i];
	}
	cout << endl;
	return 0;
}
