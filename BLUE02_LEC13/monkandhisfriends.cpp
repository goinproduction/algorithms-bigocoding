#include <iostream>
#include <set>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T, N, M;
    long long temp;
    set<long long> s;
    cin >> T;
    while (T--) {
        s.clear();
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            s.insert(temp);
        }
        for (int i = 0; i < M; i++) {
            cin >> temp;
            cout << (s.find(temp) != s.end() ? "YES" : "NO") << endl;
            s.insert(temp);
        }
    }
    return 0;
}