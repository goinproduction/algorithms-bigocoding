#include <iostream>
#include <vector>
using namespace std;

struct Vest {
	int u, v;
};

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<int> a(n), b(m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	vector<Vest> v;
   int i = 0, j = 0;
   
   while (i < n && j < m) {
      if (a[i] - x <= b[j] & b[j] <= a[i] + y) {
         v.push_back({i + 1, j + 1});
         i++;
         j++;
      }
      else if (a[i] + y < b[j]) {
         i++;
      }
      else if (a[i] - x > b[j]) {
         j++;
      }
   }

	cout << v.size() << endl;
	for (Vest &vest : v) {
		cout << vest.u << " " << vest.v << endl;
	}

	return 0;
}