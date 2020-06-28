#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;

int parent[MAX], ranks[MAX];
set<int> trees[MAX];

int findSet(int u) {
    if (u != parent[u]) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);

    if (up == vp) {
        return;
    }

    if (ranks[up] > ranks[vp]) {
        parent[vp] = up;
    }
    else if (ranks[up] < ranks[vp]) {
        parent[up] = vp;
    }
    else {
        parent[up] = vp;
        ranks[vp]++;
    }
}

int main() {
    int Q, P, T, person, tree;
    string line;
    cin >> Q;

    while (Q--) {
        cin >> P >> T;
        cin.ignore();

        while (getline(cin, line) && !line.empty()) {
            stringstream ss(line);
            ss >> person >> tree;
            trees[person].insert(tree);
        }

        for (int i = 1; i <= P; i++) {
            parent[i] = i;
            ranks[i] = 0;
        }

        for (int i = 1; i <= P; i++) {
            for (int j = i + 1; j <= P; j++) {
                if (trees[i] == trees[j]) {
                    unionSet(i, j);
                }
            }
        }

        int nSets = 0;
        for (int i = 1; i <= P; i++) {
            if (i == parent[i]) {
                nSets++;
            }
            trees[i].clear();
        }

        cout << nSets << endl;
        if (Q > 0) {
            cout << endl;
        }
    }
    return 0;
}