#include <bits/stdc++.h>
#define MAX 85
using namespace std;
const int INF = 1e9 + 7;

int C, R;
int dist[MAX][MAX];
int maxCost[MAX][MAX];
int f[MAX];

void FloydWarshall() {
    int times = 2;

    while (times--) {
        for (int k = 1; k <= C; k++) {
            for (int i = 1; i <= C; i++) {
                for (int j = 1; j <= C; j++) {
                    int maxFeast = max(maxCost[i][k], maxCost[k][j]);
                    if (dist[i][j] + maxCost[i][j] > dist[i][k] + dist[k][j] + maxFeast) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        maxCost[i][j] = maxFeast;
                    }
                }
            }
        }
    }
}

int main() {
    int u, v, w, Q, t = 1;

    while (cin >> C >> R >> Q) {
        if (C == 0) {
            break;
        }

        for (int i = 1; i <= C; i++) {
            cin >> f[i];
        }

        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++) {
                dist[i][j] = INF;
                maxCost[i][j] = max(f[i], f[j]);
            }
        }

        for (int i = 0; i < R; i++) {
            cin >> u >> v >> w;
            dist[u][v] = dist[v][u] = w;
        }

        FloydWarshall();

        if (t > 1) {
            cout << endl;
        }
        cout << "Case #" << t++ << endl;

        for (int i = 0; i < Q; i++) {
            cin >> u >> v;
            cout << (dist[u][v] == INF ? -1 : dist[u][v] + maxCost[u][v]) << endl;
        }
    }
    return 0;
}