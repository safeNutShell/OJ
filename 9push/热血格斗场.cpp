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

struct member {
	int no, fight;
};


int main() {
	vector<member> club;
	vector<pair<int, int>>race;
	member x;
	x.no = 1;
	x.fight = 1000000000;
	club.push_back(x);
	int n;
	cin >> n;
	while (n--) {
		int NO, FIGHT;
		cin >> NO >> FIGHT;
		member x;
		x.no = NO;
		x.fight = FIGHT;
		int diff = INT_MAX;
		int he = 0;
		for (int i = 0; i < club.size(); i++) {
			int a = FIGHT - club[i].fight;
			if (abs(a) < abs(diff)) {
				diff = a;
				he = club[i].no;
			}
			else if (abs(a) == abs(diff) && a > diff) {
				diff = a;
				he = club[i].no;
			}
		}
		race.push_back(make_pair(NO, he));
		club.push_back(x);
	}
	for (int i = 0; i < race.size(); i++) {
		cout << race[i].first << ' ' << race[i].second << endl;
	}
	return 0;
}
