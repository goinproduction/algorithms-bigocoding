#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const long long INF = (1LL << 30) + 7;		// Should be large enough

struct Edge {
    int source, target;
    long long weight;
};

int n;
long long dist[MAX][MAX];
string monuments[MAX];
vector<Edge> graph;

void BellmanFord(int s) {
    dist[s][s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (Edge &edge : graph) {
            int u = edge.source;
            int v = edge.target;
            long long w = edge.weight;
            if (dist[s][u] != INF && dist[s][u] + w < dist[s][v]) {
                dist[s][v] = dist[s][u] + w;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (Edge &edge : graph) {
            int u = edge.source;
            int v = edge.target;
            long long w = edge.weight;
            if (dist[s][u] != INF && dist[s][u] + w < dist[s][v]) {
                dist[s][v] = -INF;
            }
        }
    }
}

int main() {
    int q, u, v, tc = 1;
    long long w;

    while (cin >> n, n != 0) {
        graph.clear();

        for (int i = 0; i < n; i++) {
            cin >> monuments[i];           
            for (int j = 0; j < n; j++) {
                cin >> w;
                dist[i][j] = INF;
                if (i != j && w == 0) {
                    continue;
                }
                if (i == j && w >= 0) {
                    w = 0;
                }
                graph.push_back((Edge) {i, j, w});
            }
        }

        for (int i = 0; i < n; i++) {
            BellmanFord(i);
        }

        cin >> q;
        cout << "Case #" << tc++ << ":" << endl;
        while (q--) {
            cin >> u >> v;
            if (dist[u][v] <= -INF) {		// Be careful here
                cout << "NEGATIVE CYCLE" << endl;
            }
            else {
                cout << monuments[u] << "-" << monuments[v] << " ";
                if (dist[u][v] != INF) {
                    cout << dist[u][v] << endl;
                }
                else {
                    cout << "NOT REACHABLE" << endl;
                }
            }
        }
    }
    return 0;
}