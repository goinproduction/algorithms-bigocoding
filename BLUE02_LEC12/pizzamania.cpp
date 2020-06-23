#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int> &a, int left, int right, int x) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == x) {
            return true;
        }
        else if (a[mid] > x) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return false;
}

int main() {
    int t, n, m, cnt, comp;
    vector<int> a;
    cin >> t;

    for (int k = 0; k < t; k++) {
        cin >> n >> m;
        a.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        cnt = 0;

        for (int i = 0; i < n; i++) {
            comp = m - a[i];
            if (binarySearch(a, i + 1, n - 1, comp)) {
                cnt++;
            }
        }

        cout << cnt << endl;
	}
    return 0;
}