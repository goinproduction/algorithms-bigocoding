#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int a[MAX];

int BSFirst(int a[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == x && (mid == left || a[mid - 1] < x)) {
            return mid;
        }
        else if (a[mid] < x) {
            return BSFirst(a, mid + 1, right, x);
        }
        return BSFirst(a, left, mid - 1, x);
    }

    return -1;
}

int main() {
    int N, Q, x, t = 1;
    
    while (cin >> N >> Q) {
		if (N == 0 && Q == 0) {
			break;
		}
		
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        sort(a, a + N);
        cout << "CASE# " << t++ << ":" << endl;

        for (int i = 0; i < Q; i++) {
            cin >> x;
            int index = BSFirst(a, 0, N - 1, x);
            
            if (index == -1) {
                cout << x << " not found" << endl;
            }
            else {
                cout << x << " found at " << index + 1 << endl;
            }
        }
    }
    return 0;
}