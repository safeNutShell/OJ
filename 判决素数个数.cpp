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

bool isPrime(int test) {
	if (test <= 1)
		return false;
	int bound = (int)sqrt(test) + 1;
	for (int i = 2; i < bound; i++) {
		if (test % i == 0)
			return false;
	}
	return true;
}

int main() {
	int start, end;
	cin >> start >> end;
	if (start > end) {
    //注意比较大小
		int tmp = start;
		start = end;
		end = tmp;
	}
	int count = 0;
	for (int i = start; i <= end; i++) {
		if (isPrime(i)) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
