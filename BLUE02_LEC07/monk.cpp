#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue <int> pq;
    int n, val;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> val;
        pq.push(val);
        if(i < 2){
            cout <<"-1"<<endl;
        }else{
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int t = pq.top();
            pq.pop();
            cout << 1LL*f*s*t << endl;
            pq.push(f);
            pq.push(s);
            pq.push(t);
        }
    }
}
