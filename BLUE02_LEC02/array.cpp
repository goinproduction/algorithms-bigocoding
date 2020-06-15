#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
 
int fre[MAX];
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
     
    int unique = 0;
    int j = 0;
 
    for (int i = 0; i < n; i++) {
        if (fre[a[i]] == 0) {
            unique++;
        }
 
        fre[a[i]]++;
             
        while (unique == k) {
            fre[a[j]]--;
 
            if (fre[a[j]] == 0) {
                cout << j + 1 << " " << i + 1;
                return 0;
            }
 
            j++;
        }
 
    }
     
    cout << "-1 -1";
    return 0;
}