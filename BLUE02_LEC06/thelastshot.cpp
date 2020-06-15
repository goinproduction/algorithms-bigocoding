#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int N, M;
bool visited[MAX];
vector<int> graph[MAX];

int DFS(int src) {
    memset(visited, false, sizeof(visited));
    stack<int> s;
    visited[src] = true;
    s.push(src);

    int nbombs = 0;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        nbombs++;

        for (int &v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }

    return nbombs;
}

int main() {
    int u, v;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int max_bombs = 0;

    for (int i = 1; i <= N; i++) {
        max_bombs = max(max_bombs, DFS(i));
    }

    cout << max_bombs;
    return 0;
}