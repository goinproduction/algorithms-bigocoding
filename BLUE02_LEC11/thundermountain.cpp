#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const int INF = 2049;        
// Khoảng cách lớn nhất là từ điểm (0, 0) đến (1024, 1024) nên phải khởi tạo INF lớn hơn khoảng cách này

int n;
int x[MAX], y[MAX];
double dist[MAX][MAX];

double getDistance(int i, int j) {
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

void FloydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    for (int t = 1; t <= N; t++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = (i == j ? 0 : INF);
            }
        }

        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double d = getDistance(i, j);
                if (d <= 10) {
                    dist[i][j] = d;
                }
            }
        }

        FloydWarshall();
        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dist[i][j]);
            }
        }

        cout << "Case #" << t << ":" << endl;
        if (res != INF) {
            cout << fixed << setprecision(4) << res << endl;
        }
        else {
            cout << "Send Kurdy" << endl;
        }

        cout << endl;
    }
    return 0;
}