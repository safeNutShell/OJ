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

int calDays(int year, int month, int day) {
	int days = 0;
	for (int i = 1; i < year; i++) {
		if (isLeap(i))
			days += 366;
		else
			days += 365;
	}
	for (int i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			days += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			days += 30;
		else if (i == 2) {
			if (isLeap(year))
				days += 29;
			else 
				days += 28;
		}
	}
	days += day;
	return days;
}

int main() {
	int starty, startm, startd;
	int endy, endm, endd;
	cin >> starty >> startm >> startd >> endy >> endm >> endd;
	int d1 = calDays(starty, startm, startd);
	int d2 = calDays(endy, endm, endd);
	cout << d2 - d1 << endl;
	return 0;
}
