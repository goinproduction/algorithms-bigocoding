#include <bits/stdc++.h>
#define MAX 51
using namespace std;

const int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};

int W, H, res;
char table[MAX][MAX];
int visited[MAX][MAX];

bool isValid(int r, int c) {
    return r >= 0 && c >= 0 && r < H && c < W;
}

int DFS(int sr, int sc) {
    int count = 0;

    for (int i = 0; i < 8; i++) {
        int r = sr + dr[i];
        int c = sc + dc[i];

        if (isValid(r, c) && table[r][c] - table[sr][sc] == 1 && visited[r][c] == 0) {
            DFS(r, c);
            count = max(count, visited[r][c]);
        }
    }

    visited[sr][sc] = count + 1;
    cout <<"vst: "<<visited[sr][sc]<<endl;
    return visited[sr][sc];
}

int main() {
    int T = 1;

    while (true) {
        int res = 0;
        cin >> H >> W;

        if (H == 0 && W == 0) {
            break;
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> table[i][j];
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (table[i][j] == 'A') {
                    res = max(res, DFS(i, j));
                    cout <<"res: "<<res<<endl;
                }
            }
        }

        cout << "Case " << T++ << ": " << res << endl;
    }
    return 0;
}
