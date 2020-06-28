#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 100005; 

int n, m; 
int root[MAX_N];
int cnt[MAX_N];  
int maxi = 0; 
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq; 

int findRoot(int u) {
	if (u == root[u]) {
		return u; 
	}

	return root[u] = findRoot(root[u]); 
}

void unionSet(int u, int v) {
	int uu = findRoot(u); 
	int vv = findRoot(v); 

	if (uu != vv) {
		cnt[uu] += cnt[vv];
		root[vv] = uu;
		pq.push(make_pair(cnt[uu], uu));  
		maxi = max(maxi, cnt[uu]); 
	}
}

int main () {
	//freopen("input.txt", "r", stdin); 
	//freopen("output.txt", "w", stdout); 

	scanf("%d %d", &n, &m); 
	for (int i = 1; i <= n; i++) {
		cnt[i] = 1; 
		root[i] = i; 
		pq.push(make_pair(1, i)); 
	}
	
	maxi = 1; 

	for (int i = 1; i <= m; i++) {
		int u, v; 
		scanf("%d %d", &u, &v); 
		unionSet(u, v);
		while (true) {
			pair <int, int> tmp = pq.top(); 
			int r = findRoot(tmp.second); 
			if (r != tmp.second) {
				pq.pop();
				continue; 
			}

			if (cnt[r] != tmp.first) {
				pq.pop();
				continue; 
			}

			break; 
		}

		printf("%d\n", maxi - pq.top().first); 
	}

	return 0; 
}