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
	int n;
	cin >> n;
	string str;
	vector<string> strs;
	while (n--) {
		cin >> str;
		strs.push_back(str);
	}
	if (strs.size() == 1) {
		cout << strs[0].length() << endl;
		return 0;
	}
	int count = 0;
	count += strs[0].length();
	for (int i = 1; i < strs.size(); i++) {
		int bound = min(strs[i].length(), strs[i - 1].length());
		int sub = 0;
		for (int j = 0; j < bound; j++) {
			if (strs[i - 1][j] == strs[i][j])
				sub++;
			else
				break;
		}
		int remainder = strs[i].length() - sub + 1;
		count += remainder;
	}
	cout << count << endl;
	return 0;
}
