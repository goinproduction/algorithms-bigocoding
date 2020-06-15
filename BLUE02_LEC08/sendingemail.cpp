#include <bits/stdc++.h>
#define MAX 20005
using namespace std;
const int INF = 1e9 + 7;
 
int Q;
vector<pair<int, int>> graph[MAX];
int dist[MAX];
 
void Dijkstra(int s, int f) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
     
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        int w = top.first;
         
        if (u == f) {
            break;
        }
         
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
    int n, m, S, T, u, v, w;
    cin >> Q;
     
    for (int t = 1; t <= Q; t++) {
        cin >> n >> m >> S >> T;
         
        for (int i = 0; i < n; i++) {
            graph[i].clear();
            dist[i] = INF;
        }
         
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(w, v));
            graph[v].push_back(make_pair(w, u));
        }
         
        Dijkstra(S, T);
         
        cout << "Case #" << t << ": ";
         
        if (dist[T] != INF) {
            cout << dist[T] << endl;
        }
        else {
            cout << "unreachable" << endl;
        }
    }
    return 0;
}