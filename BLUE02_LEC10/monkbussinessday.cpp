#include <bits/stdc++.h>
#define MAX_N 105
#define MAX_M 1005
using namespace std;
const int INF = 1e9 + 7;

struct Edge {
    int source, target, weight;
};

int n, m;
int dist[MAX_N];
Edge graph[MAX_M];

bool BellmanFord(int s) {
    fill(dist, dist + (n + 1), INF);
    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                if (i == n - 1) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int T, u, v, w;
    cin >> T;

    while (T--) {
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[i] = (Edge) {u, v, -w};
        }

        cout << (BellmanFord(1) ? "Yes" : "No") << endl;
    }
    return 0;
}