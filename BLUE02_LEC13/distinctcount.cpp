#include <iostream>
#include <set>
using namespace std;
 
int main() {
    int T, N, X, temp;
    set<int> s;
    cin >> T;
 
    while (T--) {
        s.clear();
        cin >> N >> X;
 
        for (int i = 0; i < N; i++) {
            cin >> temp;
            s.insert(temp);
        }
 
        int diff = s.size();
 
        if (diff == X) {
            cout << "Good" << endl;
        }
        else {
            cout << (diff < X ? "Bad" : "Average") << endl;
        }
    }
    return 0;
}