#include <iostream>
#define MAX 10000
using namespace std;
int parent[MAX * 2];

int findSet(int u) {
	while (u != parent[u]) {
		u = parent[u];
	}
	return u;
}

void unionSet(int u, int v) {
	int up = findSet(u);
	int vp = findSet(v);                                                                                                                                                                                       
	parent[vp] = up;
}

int main() {
	int n, c, x, y;
	cin >> n;
	for (int i = 0; i < MAX * 2; i++)
		parent[i] = i;
	while (true) {
		cin >> c >> x >> y;
		if (c == 0 && x == 0 && y == 0) {
			break;
		}
		if (c == 1) {
			if (findSet(x) == findSet(y + MAX)) {
				cout << -1 << endl;
				continue;
			}
			unionSet(x, y);
			unionSet(x + MAX, y + MAX);
		}
		else if (c == 2) {
			if (findSet(x) == findSet(y)) {
				cout << -1 << endl;
				continue;
			}
			unionSet(x, y + MAX);
			unionSet(x + MAX, y);
		}
		else if (c == 3) {
			cout << (findSet(x) == findSet(y)) << endl;
		}
		else if (c == 4) {
			cout << (findSet(x) == findSet(y + MAX)) << endl;
		}
	}
	return 0;
}