#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> trees(n);

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    int hmin = 0, hmax = 1e9 + 7;
    long long sum;
    int res = 0;

    while (hmin <= hmax) {
        int hmid = (hmin + hmax) / 2;
        
        sum = 0;
        for (int &x : trees) {
            sum += max(0, x - hmid);
        }

        if (sum >= m) {
            res = hmid;
            hmin = hmid + 1;
        }
        else {
            hmax = hmid - 1;
        }
    }

    cout << res;
    return 0;
}