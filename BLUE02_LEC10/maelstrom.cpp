#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
 
struct Edge {
    int source, target, weight;
};
 
void BellmanFord(int s, int n, vector<int> &dist, vector<Edge> &graph) {
    dist[s] = 0;
     
    for (int i = 0; i < n - 1; i++) {
        for (Edge edge : graph) {
            int u = edge.source;
            int v = edge.target;
            int w = edge.weight;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
}
 
int main() {
    int n;
    string temp;
    cin >> n;
    vector<Edge> graph;
    vector<int> dist(n + 1, INF);
 
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cin >> temp;
 
            if (temp != "x") {
                int w = atoi(temp.c_str());
                graph.push_back({i, j, w});
                graph.push_back({j, i, w});
            }
        }
    }
 
    BellmanFord(1, n, dist, graph);
     
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dist[i]);
    }
    cout << res;
 
    return 0;
}