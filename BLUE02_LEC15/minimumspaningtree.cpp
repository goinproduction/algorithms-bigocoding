#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
const int INF = 1e9 + 7;

int N, M;
bool visited[MAX];
int dist[MAX];
vector<pair<int, int>> graph[MAX];

long long Prim(int s) {
    fill(dist, dist + (N + 1), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (pair<int, int> &neighbor : graph[u]) {
            int v = neighbor.second;
            int w = neighbor.first;

            if (!visited[v] && w < dist[v]) {
                dist[v] = w;
                pq.push(make_pair(w, v));
            }
        }
    }

    long long res = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            continue;
        }
        res += dist[i];
    }
    return res;
}

int main() {
    int u, v, w;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }

    cout << Prim(N);
    return 0;
}