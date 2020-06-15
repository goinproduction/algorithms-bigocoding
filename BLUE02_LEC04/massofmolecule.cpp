#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int mass(char c) {
    return c == 'H' ? 1 : (c == 'C' ? 12 : 16);
}
 
int main() {
    string s;
    cin >> s;
 
    stack<int> atom;
    int w, mol;
 
    for (char c : s) {
        if (isalpha(c)) {
            atom.push(mass(c));
        }
        else if (isdigit(c)) {
            mol = atom.top() * (c - '0');
            atom.pop();
            atom.push(mol);
        }
        else if (c == '(') {
            atom.push(-1);
        }
        else if (c == ')') {
            w = 0;
            while (atom.top() != -1) {
                w += atom.top();
                atom.pop();
            }
            atom.pop();
            atom.push(w);
        }
    }
     
    int sum = 0;
    while (!atom.empty()) {
        sum += atom.top();
        atom.pop();
    }
 
    cout << sum;
    return 0;
}