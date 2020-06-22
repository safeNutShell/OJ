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

bool isLeap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int main() {
	int year, month;
	cin >> year >> month;
	int days = 0;
	for (int i = 1900; i < year; i++) {
		if (isLeap(i))
			days += 366;
		else
			days += 365;
	}
	bool thisLeap = isLeap(year);
	for (int i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11) {
			days += 31;
		}
		if (i == 4 || i == 6 || i == 8 || i == 10 || i == 12) {
			days += 30;
		}
		if (i == 2 && thisLeap == true) {
			days += 29;
		}
		if (i == 2 && thisLeap == false) {
			days += 28;
		}
	}
	int start = days % 7;//加一即为星期几
	int d = 0;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) {
		d = 31;
	}
	if (month == 4 || month == 6 || month == 8 || month == 10 || month == 12) {
		d = 30;
	}
	if (month == 2 && thisLeap == true) {
		d = 29;
	}
	if (month == 2 && thisLeap == false) {
		d = 28;
	}
	vector<int> ans;
	int begin = (start + 1) % 7;
	for (int i = 0; i < begin; i++) {
		ans.push_back(0);
	}
	for (int i = 1; i <= d; i++) {
		ans.push_back(i);
	}
	cout << "Sun Mon Tue Wed Thu Fri Sat"<< endl;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 0) {
			cout << "    ";
		}
		else if (ans[i] < 10) {
			cout << "  " << ans[i] << " ";
		}
		else if (ans[i] >= 10) {
			cout << " " << ans[i] << " ";
		}
		if (i % 7 == 6) {
			cout << "\n";
		}
	}
}
