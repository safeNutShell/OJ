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
//#define INT_MAX 2147483647
using namespace std;


int main() {
	int n;
	cin >> n;
	int type, key;
	priority_queue<int, vector<int>, greater<int>>heap;
	while (n--) {
		cin >> type;
		if (type == 1) {
			cin >> key;
			heap.push(key);
			
		}
		else {	
			cout << heap.top() << endl;
			heap.pop();
		}
	}
	return 0;
}
