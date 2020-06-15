#include <bits/stdc++.h>
#define MAX 505
using namespace std;
const int INF = 1e9 + 7;

vector<pair<int, int>> graph[MAX], graphS[MAX], graphD[MAX];
int dist[MAX], distS[MAX], distD[MAX];

void Dijkstra(int s, int dist[], vector<pair<int, int>> (&graph)[MAX]) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;
	
	while (!pq.empty()) {
		pair<int, int> top = pq.top();
		pq.pop();
		
		int u = top.second;
		int w = top.first;
		
		if (w > dist[u]) {
			continue;
		}
		
		for (pair<int, int> &neighbor : graph[u]) {
			if (w + neighbor.first < dist[neighbor.second]) {
				dist[neighbor.second] = w + neighbor.first;
				pq.push(make_pair(dist[neighbor.second], neighbor.second));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M, S, D, u, v, w;
	
	while (true) {
		cin >> N >> M;
		
		if (N == 0 && M == 0) {
			break;
		}
		
		for (int i = 0; i < N; i++) {
			graph[i].clear();
			graphS[i].clear();
			graphD[i].clear();
			dist[i] = INF;
			distS[i] = INF;
			distD[i] = INF;
		}
		
		cin >> S >> D;
		
		for (int i = 0; i < M; i++) {
			cin >> u >> v >> w;
			graphS[u].push_back(make_pair(w, v));
			graphD[v].push_back(make_pair(w, u));
		}
		
		Dijkstra(S, distS, graphS);
		Dijkstra(D, distD, graphD);
		int shortestPath = distS[D];
		
		for (int u = 0; u < N; u++) {
			for (pair<int, int> &neighbor : graphS[u]) {
				int v = neighbor.second;
				int w = neighbor.first;
				
				if (distS[u] + w + distD[v] != shortestPath) {
					graph[u].push_back(neighbor);
				}
			}
		}
		
		Dijkstra(S, dist, graph);
		cout << (dist[D] != INF ? dist[D] : -1) << endl;
	}
	return 0;
}