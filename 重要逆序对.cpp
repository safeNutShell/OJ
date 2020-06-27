#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
//#define INT_MAX 2147483647

using namespace std;

long long int sum;

void merge(int* s, int* tmp, int left, int right, int mid) {
	int i = left, j = mid + 1, k = left;
	int ptr = left;
	while (i <= mid && j <= right) {
		if (s[i] > s[j]) {
			tmp[k++] = s[j];
			while (s[ptr] <= 2 * s[j] && ptr <= mid) {
				ptr++;
			}
			if (ptr != mid + 1) {
				sum += mid - ptr + 1;
			}
			j++;
		}
		else {
			tmp[k++] = s[i++];
		}
	}
	while (i <= mid) tmp[k++] = s[i++];
	while (j <= right) tmp[k++] = s[j++];
	for (int m = left; m <= right; m++)
		s[m] = tmp[m];
}

void mergeSort(int* s, int* tmp, int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		mergeSort(s, tmp, left, mid);
		mergeSort(s, tmp, mid + 1, right);
		merge(s, tmp, left, right, mid);
	}
}

int main() {
	int n;
	cin >> n;
	int* s = new int[n];
	int* tmp = new int[n];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	mergeSort(s, tmp, 0, n - 1);
	cout << sum << endl;
	delete[] s;
	delete[] tmp;
	return 0;
}
