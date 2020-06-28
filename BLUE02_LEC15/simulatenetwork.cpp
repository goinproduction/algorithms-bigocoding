#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int MAX = 1e5 + 10;
const int INF = 1e9;

vector<pii > graph[MAX];
vector<int> dist(MAX, INF);
bool visited[MAX];

struct option {
    bool operator() (const pii &a, const pii &b) const {
        return a.second > b.second;
    }
}; 

void prim(int src) {
    priority_queue<pii, vector<pii >, option > pq;
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
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m;
    for (int u, v, w, i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    prim(1);
    priority_queue<int> mstCable;
    for (int i = 2; i <= n; i++) {
        mstCable.push(dist[i]); // add all edges in mst to max heap
    }
    cin >> q;
    priority_queue<int, vector<int>, greater<int> > newCables;
    for (int x, i = 0; i < q; i++) {
        cin >> x;
        newCables.push(x);
    }
    long long res = 0;
    while (!mstCable.empty()) {
        int usedCable = mstCable.top();
        mstCable.pop();
        if (!newCables.empty() && newCables.top() < usedCable) {
            usedCable = newCables.top(); // replace old cable by new cable
            newCables.pop();
        }
        res += usedCable;
    }
    cout << res;
    return 0;
}