#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int count1 = 0, count5 = 0, count10 = 0;
	int count, num;
	cin >> count;
	while (count--) {
		cin >> num;
		if (num == 1)
			count1++;
		if (num == 5)
			count5++;
		if (num == 10)
			count10++;
	}
	cout << count1 << endl << count5 << endl << count10 << endl;
	return 0;
}
