#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    vector<int> a;

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long count = 0;
    vector<int>::iterator it;
    for (int i = 0; i < n; i++) {
        it = lower_bound(a.begin(), a.end(), a[i] + k);
        if (it != a.end() && *it == a[i] + k) {
            count++;
        }        
    }
    cout << count;
    return 0;
}