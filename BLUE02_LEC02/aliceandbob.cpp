#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> chocolate(n);

    for (int i = 0; i < n; i++) {
        cin >> chocolate[i];
    }

    int t_alice = 0, t_bob = 0;
    int i = 0, j = n - 1;

    while (i <= j) {
        if (t_alice + chocolate[i] <= t_bob + chocolate[j]) {
            t_alice += chocolate[i];
            i++;
        }
        else {
            t_bob += chocolate[j];
            j--;
        }
    }

    cout << i << " " << n - i;
    return 0;
}