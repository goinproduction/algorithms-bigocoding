#include <bits/stdc++.h>
#define MAX_N 100 + 5
#define MAX_M 100 * 50 + 5
using namespace std;

struct Edge {
    int source, target;
    double weight;
};

int n, m;
double prob[MAX_N];
Edge graph[MAX_M];

void BellmanFord() {
    fill(prob, prob + (n + 1), -1.0);
    prob[1] = 1.0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            double w = graph[j].weight;

            prob[u] = max(prob[u], prob[v] * w);
            prob[v] = max(prob[v], prob[u] * w);
        }
    }
}

int main() {
    int u, v, c;

    while (cin >> n, n != 0) {
        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> c;
            graph[i] = (Edge) {u, v, c / 100.0};
        }

        BellmanFord();
        cout << fixed << setprecision(6) << prob[n] * 100.0 << " percent" << endl;
    }
    return 0;
}