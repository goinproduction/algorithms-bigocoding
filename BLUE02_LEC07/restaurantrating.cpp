#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x, p;
    cin >> n;
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    while(n--){
        cin >> p;
        if(p == 1){ 
            cin >> x;
            q1.push(x);
            if((q1.size() + q2.size()) / 3 > 0){
                if((q2.size() + q1.size()) % 3 == 0){
                    q2.push(q1.top());
                    q1.pop();
                }else{
                    if(q2.top() < q1.top()){
                        q2.push(q1.top());
                        q1.pop();
                        q1.push(q2.top());
                        q2.pop();
                    }
                }
            }
        }else{
            if(!q2.empty()){
                cout << q2.top() << endl;
            }else{
                cout <<"No reviews yet"<<endl;
            }
        }
    }
}
