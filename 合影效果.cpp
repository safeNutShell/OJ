#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

bool cmpm(double a, double b) {
	return a < b;
}

bool cmpf(double a, double b) {
	return a > b;
}

int main() {
	int n;
	vector<double>m;
	vector<double>f;
	string sex;
	double height;
	cin >> n;
	while (n--) {
		cin >> sex >> height;
		if (sex == "male")
			m.push_back(height);
		else
			f.push_back(height);
	}
	sort(m.begin(), m.end(), cmpm);
	sort(f.begin(), f.end(), cmpf);
	for (int i = 0; i < m.size(); i++) printf("%.2f ", m[i]);
	for (int i = 0; i < f.size(); i++) {
		printf("%.2f", f[i]);
		if (i < f.size() - 1)
			cout << ' ';
		else
			cout << endl;
	}
	return 0;
}
