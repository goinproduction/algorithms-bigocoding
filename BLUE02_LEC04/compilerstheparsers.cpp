#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int main() {
    int T, ans;
    string s;
    cin >> T;
 
    for (int k = 0; k < T; k++) {
        cin >> s;
        stack<char> expr;
        ans = 0;
 
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '<') {
                expr.push(s[i]);
            }
            else if (expr.empty()) {
                break;
            }
            else {
                expr.pop();
                ans = (expr.empty() ? i + 1 : ans);
            }
        }
 
        cout << ans << endl;
    }
    return 0;
}