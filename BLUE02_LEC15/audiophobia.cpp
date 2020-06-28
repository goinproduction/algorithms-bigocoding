#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define MAX 110
const int INF = 1e9;
vector<pii > mstGraph[MAX];
vector<pii > graph[MAX];
bool visited[MAX];
int dist[MAX];
int path[MAX];
int C, S, Q;

struct option {
    bool operator() (const pii &a, const pii &b) const {
        return a.second > b.second;
    }
};

void prim(int src) {
    priority_queue<pii, vector<pii >, option> pq;
    pq.push(make_pair(src, 0));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(make_pair(v, w));
                path[v] = u;
            }
        }
    }
    
    for (int u = 2; u <= C; u++) {
        if (path[u] != -1) {
            int v = path[u];
            int w = dist[u];
            mstGraph[u].push_back(make_pair(v, w));
            mstGraph[v].push_back(make_pair(u, w));
        }
    }
}

int dfs(int src, int dst, int level) {
    if (src == dst)
        return level;
    visited[src] = true;
    for (int i = 0; i < mstGraph[src].size(); i++) {
        int v = mstGraph[src][i].first;
        int w = mstGraph[src][i].second;
        if (!visited[v]) {
            int tmpLevel = dfs(v, dst, max(level, w));
            if (tmpLevel != INF)
                return tmpLevel;
        }
    }
    return INF;
}

int main() {
    int u, v, w;
    int tc = 1;
    while (true) {
        cin >> C >> S >> Q;
        if (C == 0 && S == 0 && Q == 0)
            break;
        
        for (int i = 1; i <= C; i++) {
            mstGraph[i].clear();
            graph[i].clear();
            visited[i] = false;
            dist[i] = INF;  
            path[i] = -1;
        }
        
        for (int i = 0; i < S; i++) {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        
        for (int i = 1; i <= C; i++)
            if (!visited[i])
                prim(i);
        
        if (tc != 1)
            cout << endl;
        cout << "Case #" << tc++ << "\n";
        for (int i = 0; i < Q; i++) {
            cin >> u >> v;
            memset(visited, false, sizeof(visited));
            int level = dfs(u, v, 0);
            if (level != INF)
                cout << level;
            else
                cout << "no path";
            cout<<"\n";
        }
    }
    return 0;
}