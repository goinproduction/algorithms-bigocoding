#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
const int INF = 1e9 + 7;
 
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
vector<string> cities;
 
int getIndex(string name) {
    for (int i = 0; i < cities.size(); i++) {
        if (name == cities[i]) {
            return i;
        }
    }
    return -1;
}
 
void Dijkstra(int s, int f) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
 
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
 
        int u = top.second;
        int w = top.first;
 
        if (u == f) {
            break;
        }
 
        for (pair<int, int> &neighbor : graph[u]) {
            if (w + neighbor.first < dist[neighbor.second]) {
                dist[neighbor.second] = w + neighbor.first;
                pq.push(make_pair(dist[neighbor.second], neighbor.second));
            }
        }
    }
}
 
int main() {
    int T, N, Q;
    int neighbors, u, v, w;
    string name, sCity, fCity;
    cin >> T;
 
    while (T--) {
        cin >> N;
         
        for (int i = 1; i <= N; i++) {
            graph[i].clear();
        }
        cities.clear();
         
        for (int u = 1; u <= N; u++) {
            cin >> name >> neighbors;
            cities.push_back(name);
 
            for (int i = 0; i < neighbors; i++) {
                cin >> v >> w;
                graph[u].push_back(make_pair(w, v));
            }
        }
 
        cin >> Q;
 
        for (int i = 0; i < Q; i++) {
            cin >> sCity >> fCity;
            int s = getIndex(sCity) + 1;
            int f = getIndex(fCity) + 1;
            dist = vector<int>(N + 1, INF);
            Dijkstra(s, f);
            cout << dist[f] << endl;
        }
    }
    return 0;
}