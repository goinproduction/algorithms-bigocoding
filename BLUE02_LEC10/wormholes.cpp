#include <bits/stdc++.h>
#define MAX_V 1005
#define MAX_E 2005
using namespace std;
const int INF = 1e9 + 7;

struct Edge {
    int source, target, weight;
};

int n, m;
int dist[MAX_V];
Edge graph[MAX_E];

bool BellmanFord(int s) {
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

    for (int i = 0; i < m; i++) {
        int u = graph[i].source;
        int v = graph[i].target;
        int w = graph[i].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false;
        }
    }
    return true;
}

int main() {
    int T, x, y, t;
    cin >> T;

    while (T--) {
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> x >> y >> t;
            graph[i] = (Edge) {x, y, t};
        }

		    cout << (!BellmanFord(0) ? "possible" : "not possible") << endl;
    }
    return 0;
}