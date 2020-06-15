#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> a(12);

    for (int i = 0; i < 12; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    int n_months = 0;

    for (int height : a) {
        if (k <= 0) {
            break;
        }

        n_months++;
        k -= height;
    }

    cout << (k <= 0 ? n_months : -1);
    return 0;
}