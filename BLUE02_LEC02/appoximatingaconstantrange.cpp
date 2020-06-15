#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
 
int fre[MAX];
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int j = 0, diff = 0;
    int longest_range = 0;
 
    for (int i = 0; i < n; i++) {
        if (fre[a[i]] == 0) {
            diff++;
        }
        fre[a[i]]++;
 
        while (j < n && diff > 2) {
            if (fre[a[j]] == 1) {
                diff--;
            }
            fre[a[j]]--;
            j++;
        }
 
        longest_range = max(longest_range, i - j + 1);
    }
 
    cout << longest_range;
    return 0;
}