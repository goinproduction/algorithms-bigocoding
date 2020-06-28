#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
const int INF = 0x3f3f3f3f;

int dist[MAX];
bool visited[MAX];
vector<pair<int, int> > graph[MAX];

void Prim(int source) {
    priority_queue<pair<int , int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0 , source));
    dist[source] = 0;

    while (!pq.empty()) {
        pair <int , int> tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        visited[u] = true;

        for (int i = 0; i < graph[u].size(); i++) {
            pair<int , int> neighbor = graph[u][i];
            int v = neighbor.first;
            int c = neighbor.second;

            if (!visited[v] && dist[v] > c) {
                dist[v] = c;
                pq.push(make_pair(c , v));
            }
        }
    }
}

int main()
{
    // freopen("INPUT.INP", "rt", stdin);
    ios::sync_with_stdio(false);
    int t, p, n, m, a, b, c;
    cin >> t;
    while(t--)
    {
        cin >> p >> n >> m;
        for (int i = 0; i < n; i++) {
            graph[i].clear();
            visited[i] = false;
            dist[i] = INF;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            graph[a - 1].push_back(make_pair(b - 1, c));
            graph[b - 1].push_back(make_pair(a - 1, c));
        }
        Prim(0);
        int res = 0;
        for (int i = 0; i < n; i++)
            res += dist[i];
        cout << res * p << "\n";
    }
    return 0;
}