#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), sorted_a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }

    sort(sorted_a.begin(), sorted_a.end());
    int l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != sorted_a[i]) {
            l = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != sorted_a[i]) {
            r = i;
            break;
        }
    }

    for (int i = l, j = r; i < j; i++, j--) {
        swap(a[i], a[j]);
    }

    if (a != sorted_a) {
        cout << "no";
        return 0;
    }

    cout << "yes" << endl;
    cout << l + 1 << " " << r + 1;
    return 0;
}