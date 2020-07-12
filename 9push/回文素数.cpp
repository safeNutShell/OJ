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

bool isPrime(int a) {
	if (a == 2) return true;
	int bound = (int)sqrt(a) + 1;
	for (int i = 2; i <= bound; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	set<int>ans;
	if (n == 1) {
		for (int i = 2; i < 10; i++) {
			if (isPrime(i))
				ans.insert(i);
		}
	}
	else {
		for (int i = pow(10, n / 2 - 1); i < pow(10, n / 2); i++) {
			int palindrome;
			if (n % 2 == 0) {
				//如果位数是偶数
				string tmp = to_string(i);
				int l = 0, r = (int)tmp.size() - 1;
				while (l < r) {
					swap(tmp[l], tmp[r]);
					l++;
					r--;
				}
				palindrome = stoi(to_string(i) + tmp);
				if (isPrime(palindrome))
					ans.insert(palindrome);
			}
			else {
				for (int mid = 0; mid <= 9; mid++) {
					string tmp = to_string(i);
					int l = 0, r = (int)tmp.size() - 1;
					while (l < r) {
						swap(tmp[l], tmp[r]);
						l++;
						r--;
					}
					palindrome = stoi(to_string(i) + to_string(mid) + tmp);
					if (isPrime(palindrome))
						ans.insert(palindrome);
				}
			}
		}
	}
	int c = 0;
	cout << ans.size() << endl;
	for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it;
		c++;
		if (c < ans.size())
			cout << ' ';
		else
			cout << endl;
	}
	return 0;
}
