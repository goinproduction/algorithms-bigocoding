#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
 
    int j = 0, max_book = 0, read_book = 0;
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
 
        while (t < a[i]) {
            t += a[j];
            j++;
            read_book--;
        }
         
        t -= a[i];
        read_book++;
        max_book = max(max_book, read_book);
    }
 
    cout << max_book;
    return 0;
}