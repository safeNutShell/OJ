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

string haabMonth[19] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin","mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet" };
string tDay[20] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };

int haabToDay(int d, string m, int y) {
	int sum = 0;
	for (int i = 0; i < y; i++)
		sum += 365;
	for (int i = 0; i < 19; i++) {
		if (m != haabMonth[i])
			sum += 20;
		else
			break;
	}
	sum += d;
	return sum;
}

void tt(int days) {
	int year = days / 260;
	days = days % 260;
	int i = days % 13 + 1;
	int j = days % 20;
	cout << i << ' ' << tDay[j] << ' ' << year << endl;
}

int main() {
	int n;
	cin >> n;
	cout << n << endl;
	while (n--) {
		string tmp, month;
		int year;
		cin >> tmp >> month >> year;
		tmp.substr(0, tmp.size() - 1);
		int day = stoi(tmp);
		int sum = haabToDay(day, month, year);
		tt(sum);
	}
	return 0;
}
