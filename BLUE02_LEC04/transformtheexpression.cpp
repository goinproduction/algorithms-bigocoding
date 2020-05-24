#include<iostream>
#include<stack>
#include<ctype.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    stack<char> b;
    string a;
    for(int i=0; i<n; i++){
        cin >> a;
        for(int j=0; j < a.size(); j++){
            if(isalpha(a[j])){
                cout << a[j];
            }else if(a[j] == '+' || a[j] == '-' || a[j] == '*' || a[j] == '/' || a[j] == '^'){
              b.push(a[j]);  
            }else if(a[j] == ')'){
                
                cout << b.top();
                b.pop();
                
            }
        }
        cout << endl;
    }
}
