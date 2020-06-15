#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const int INF = 1e9 + 7;
 
int N, R;
vector<pair<int, int> > graph[MAX];
 
vector<int> Dijkstra(int s) {
    vector<int> dist(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
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
         
        for (int i = 0; i < graph[u].size(); i++) {
            pair<int, int> neighbor = graph[u][i];
             
            if (w + neighbor.first < dist[neighbor.second]) {
                dist[neighbor.second] = w + neighbor.first;
                pq.push(make_pair(dist[neighbor.second], neighbor.second));
            }
        }
    }
     
    return dist;
}
 
int main() {
    int T, s, d, u, v;
    cin >> T;
     
    for (int t = 1; t <= T; t++) {
        cin >> N >> R;
         
        for (int i = 0; i < N; i++) {
            graph[i].clear();
        }
         
        for (int i = 0; i < R; i++) {
            cin >> u >> v;
            graph[u].push_back(make_pair(1, v));
            graph[v].push_back(make_pair(1, u));
        }
         
        cin >> s >> d;
         
        vector<int> distS = Dijkstra(s);
        vector<int> distD = Dijkstra(d);
        int res = 0;
         
        for (int i = 0; i < N; i++) {
            res = max(res, distS[i] + distD[i]);
        }
         
        cout << "Case " << t << ": " << res << endl;
    }
    return 0;
}