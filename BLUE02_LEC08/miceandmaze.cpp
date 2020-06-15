#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const int INF = 1e9 + 7;
 
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
 
void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
 
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
 
        int u = top.first;
        int w = top.second;
 
        for (pair<int, int> &neighbor : graph[u]) {
            if (w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
    }
}
 
int main() {
    int N, E, T, M;
    int u, v, w;
    cin >> N >> E >> T >> M;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
 
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[v].push_back(make_pair(u, w));
    }
 
    Dijkstra(E);
 
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= T) {
            count++;
        }
    }
 
    cout << count;
    return 0;
}