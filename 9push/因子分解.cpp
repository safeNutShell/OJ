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

const int maxn = 100010;
int flag[maxn] = { false };
int prime[maxn];
int primeCount = 0;

void findPrime() {
	flag[0] = flag[1] = true;
	for (int i = 2; i < maxn; i++) {
		if (flag[i] == false) {
			prime[primeCount++] = i;
			for (int j = i + i; j < maxn; j += i) {
				flag[j] = true;
			}
		}
	}
}

struct element {
	int p, exp;
}a[10];

int main() {
	int n;
	cin >> n;
	findPrime();
	int bound = (int)sqrt(n) + 1;
	int c = 0;
	if (n == 1)
		cout << "1" << endl;
	else {
		for (int i = 0; prime[i] <= bound; i++) {
			if (n % prime[i] == 0) {
				a[c].p = prime[i];
				a[c].exp = 0;
				while (n % prime[i] == 0) {
					a[c].exp++;
					n /= prime[i];
				}
				c++;
			}
		}
		if (n != 1) {
			a[c].p = n;
			a[c].exp = 1;
		}
		if (a[0].exp == 1)
			cout << a[0].p;
		else
			cout << a[0].p << "^" << a[0].exp;
		for (int i = 1; i < c; i++) {
			if (a[i].exp == 1)
				cout << "*" << a[i].p;
			else
				cout << "*" << a[i].p << "^" << a[i].exp;
		}
		cout << endl;
	}
	return 0;
}
