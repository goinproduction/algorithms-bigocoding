#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq, pqRemove;
    int Q;
    cin >> Q;

    int type, value;

    for (int k = 0; k < Q; k++) {
        cin >> type;

        if (type == 1) {
            cin >> value;
            pq.push(value);
        }
        else if (type == 2) {
            cin >> value;
            pqRemove.push(value);
        }
        else {
            while (!pqRemove.empty() && pq.top() == pqRemove.top()) {
                pq.pop();
                pqRemove.pop();
            }

            cout << pq.top() << endl;
        }
    }
    return 0;
}