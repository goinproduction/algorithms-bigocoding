#include <bits/stdc++.h>
#define MAX_N 1005
#define MAX_M 5005
using namespace std;
const int INF = 1e9 + 7;

struct Edge {
    int source, target, weight;
};

int n, m;
int dist[MAX_N];
Edge graph[MAX_M];

void BellmanFord(int s) {
    fill(dist, dist + n, INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = -INF;
            }
        }
    }
}

int main() {
    int u, v, w, q, s, f;

    while (cin >> n >> m >> q >> s, n != 0) {
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[i] = (Edge) {u, v, w};
        }

        BellmanFord(s);

        while (q--) {
            cin >> f;

            if (dist[f] == INF) {
                cout << "Impossible" << endl;
            }
            else if (dist[f] == -INF) {
                cout << "-Infinity" << endl;
            }
            else {
                cout << dist[f] << endl;
            }
        }
        cout << endl;
    }
    return 0;
}