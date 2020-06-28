#include <bits/stdc++.h>
using namespace std;
const int MAX = 30005;

int parent[MAX], cnt[MAX];

int findSet(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    if (up != vp) {
        parent[up] = vp;
        cnt[vp] += cnt[up];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int u, v, t, n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            cnt[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            unionSet(u, v);
        }

        int res = -1;
        for (int i = 1; i <= n; i++) {
            res = max(res, cnt[i]);
        }
        cout << res << endl;
    }

    return 0;
}