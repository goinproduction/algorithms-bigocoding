#include <iostream>
#include <stack>
using namespace std;
const int MAX = 1005;
 
int main() {
    int n;
    int trucks[MAX];
    stack<int> side_trucks;
 
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
     
        for (int i = 0; i < n; i++) {
            cin >> trucks[i];
        }
 
        int ordering = 1;
        int i = 0;
         
        while (i < n) {
            if (trucks[i] == ordering) {
                i++;
                ordering++;
            }
            else if (!side_trucks.empty() && side_trucks.top() == ordering) {
                ordering++;
                side_trucks.pop();
            }
            else {
                side_trucks.push(trucks[i]);
                i++;
            }
        }
 
        while (!side_trucks.empty() && side_trucks.top() == ordering) {
            ordering++;
            side_trucks.pop();
        }
 
        cout << (ordering == n + 1 ? "yes" : "no") << endl;
        while (!side_trucks.empty()) {
            side_trucks.pop();
        }
    }
    return 0;
}