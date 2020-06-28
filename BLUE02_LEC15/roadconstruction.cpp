#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
const int inf = 1e7;

int test;
map <string , int> my_map;
int n, m;
int dist[MAX];
bool visited[MAX];
vector<pair<int, int> > adj[MAX];

void Prim(int source) {
    priority_queue<pair<int , int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
        visited[i] = false;
    }
    pq.push(make_pair(0 , source));
    dist[source] = 0;

    while (!pq.empty()) {
        pair <int , int> tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        visited[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            pair<int , int> neighbor = adj[u][i];
            int v = neighbor.first;
            int c = neighbor.second;

            if (!visited[v] && dist[v] > c) {
                dist[v] = c;
                pq.push(make_pair(c , v));
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res += dist[i];

    if (res >= inf) {
        cout << "Impossible\n";
    }
    else {
        cout << res << endl;
    }
}

int main () {
    //freopen("input.txt" , "r" , stdin);
    cin >> test;
    int t = test;

    while (test--) {
        cout << "Case " << t - test << ": ";
        cin >> m;

        my_map.clear();
        n = 0;

        for (int i = 1; i <= 2*m; i++)
            adj[i].clear();

        for (int i = 1; i <= m; i++) {
            string s1 , s2;
            int w;

            cin >> s1 >> s2 >> w;
            if (my_map.find(s1) == my_map.end()) {
                my_map[s1] = ++n;
            }

            if (my_map.find(s2) == my_map.end()) {
                my_map[s2] = ++n;
            }

            int u = my_map[s1];
            int v = my_map[s2];
            adj[u].push_back(make_pair(v , w));
            adj[v].push_back(make_pair(u , w));
        }
        Prim(1);
    }
    return 0;
}