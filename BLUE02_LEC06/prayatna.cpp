#include <bits/stdc++.h>
#define MAX 100000 + 5
using namespace std;

int V, E;
bool visited[MAX];
vector<int> graph[MAX];

void DFS(int scr) {
    stack<int> s;
    visited[scr] = true;
    s.push(scr);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        for (int &v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
}

int main() {
    int Q, u, v;
    cin >> Q;

    while (Q--) {
        cin >> V >> E;

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            graph[i].clear();
        }

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                DFS(i);
            }
        }

        cout << count << endl;
    }
    return 0;
}