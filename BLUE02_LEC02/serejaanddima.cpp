#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> cards(n);
 
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
 
    int res[2] = {0};
    int player = 0;
    int i = 0, j = n - 1;
 
    while (i <= j) {
        if (cards[i] > cards[j]) {
            res[player] += cards[i];
            i++;
        }
        else {
            res[player] += cards[j];
            j--;
        }
 
        player = 1 - player;
    }
 
    cout << res[0] << " " << res[1];
    return 0;
}