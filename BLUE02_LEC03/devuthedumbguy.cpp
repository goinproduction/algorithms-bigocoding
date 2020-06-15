#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	
	sort(c.begin(), c.end());
	
	long long min_time = 0;
	
	for (int chapters : c) {
		min_time += 1LL * chapters * x;
		if (x > 1) {
			x--;
		}
	}
	
	cout << min_time;
	return 0;
}