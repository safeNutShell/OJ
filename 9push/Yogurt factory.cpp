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

struct day {
	int cost, delivery, no;
}d[10010];

int main() {
	int n, s;
	cin >> n >> s;
	int co, de;
	for (int i = 0; i < n; i++) {
		cin >> co >> de;
		day today;
		today.cost = co;
		today.delivery = de;
		today.no = i;
		d[i] = today;
	}
	long long int sum = 0;
	int ptr = 0;
	sum += (long long int)d[0].cost * d[0].delivery;
	for (int i = 1; i < n; i++) {
		int now = d[i].cost;
		int pre = d[ptr].cost + s * (i - ptr);
		if (now < pre) {
			sum += (long long int)now * d[i].delivery;
			ptr = i;
		}
		else {
			sum += (long long int)pre * d[i].delivery;
		}
	}
	cout << sum << endl;
	return 0;
}
