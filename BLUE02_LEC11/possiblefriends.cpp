#include <bits/stdc++.h>
#define MAX 55
using namespace std;
const int INF = 1e9 + 7;

int M;
string matrix[MAX];
int dist[MAX][MAX];

void FloydWarshall() {
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int T;
    string s;
    cin >> T;

    while (T--) {
        cin >> s;
        M = s.length();

        for (int i = 0; i < M; i++) {
            if (i == 0) {
                matrix[0] = s;
			      }
			      else {
				        cin >> matrix[i];
			      }

            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == 'Y') {
                    dist[i][j] = 1;
                }
                else {
                    dist[i][j] = (i == j ? 0 : INF);
                }
            }
        }

        FloydWarshall();
        int nfriends = 0, index = 0;

        for (int i = 0; i < M; i++) {
            int count = 0;
            
            for (int j = 0; j < M; j++) {
                if (dist[i][j] == 2) {
                    count++;
                }
            }

            if (count > nfriends) {
                nfriends = count;
                index = i;
            }
        }

        cout << index << " " << nfriends << endl;
    }
    return 0;
}