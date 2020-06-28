#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define MAX 3005
const int INF = 1e9;
vector<pair<int, int> > graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N;
void printAns()
{
    long long ans = 0;
    for (int i = 0; i<N; i++)
    {
        if (path[i] == -1)
            continue;
        ans += dist[i];
    }
    cout << ans;
}
void Prims(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (!visited[v] && dist[v] > w)
            {
                dist[v] = w;
                pq.push(make_pair(w, v));
                path[v] = u;
            }
        }
    }
}
int main()
{
    int M, u, v, w;
    cin >> N >> M;
    memset(path, -1, sizeof(path));
    for (int i = 0; i<M; i++)
    {
        bool add = true;
        cin >> u >> v >> w;
        --u; --v;
        pair<int, int> t = make_pair(v, w);
        for (int j = 0; j < graph[u].size(); ++j)
            if (graph[u][j] == t)
            {
                if (w < graph[u][j].second)
                {
                    graph[u][j].second = w;
                    t = make_pair(u, w);
                    int k;
                    for (k = 0; k < graph[v].size() && graph[v][k] != t; ++k);
                    graph[v][k].second = w;

                }
                add = false;
                break;
            }
        if (add)
        {
            graph[u].push_back(t);
            graph[v].push_back(make_pair(u, w));
        }
    }
    int s;
    cin >> s;
    --s;
    Prims(s);
    printAns();
    return 0;
}