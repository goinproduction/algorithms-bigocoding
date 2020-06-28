#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;

int parent[MAX];

int findSet(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    parent[up] = vp;
}

bool isSameSet(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first == p2.first || p1.second == p2.second;
}

int main() {
    int u, v, n;
    cin >> n;
    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        cin >> p[i].first >> p[i].second;

        for (int j = 0; j < i; j++) {
            if (isSameSet(p[i], p[j])) {
                unionSet(i, j);
            }
        }
    }

    int nGroup = 0;
    for (int i = 0; i < n; i++) {
        if (i == parent[i]) {
            nGroup++;
        }
    }

    cout << nGroup - 1;
    return 0;
}