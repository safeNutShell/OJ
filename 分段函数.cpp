#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

double yy1(double x) {
	return 2.5 - x;
}

double y2(double x) {
	return 9 * x - 1.5 * x * x - 11.5;
}

double y3(double x) {
	return x / 2 - 1.5;
}

int main() {
	double x;
	cin >> x;
	if (x >= 0 && x < 5)
		printf("%.3f\n", yy1(x));
	else if (x >= 5 && x < 10)
		printf("%.3f\n", y2(x));
	else if (x >= 10 && x < 20)
		printf("%.3f\n", y3(x));
	return 0;
}
