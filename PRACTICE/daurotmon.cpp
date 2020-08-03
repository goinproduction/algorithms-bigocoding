#include<bits/stdc++.h>
using namespace std;
#define db double
int main(){
    // x y
    // z t
    // 0 1
    // 2 3
    // 4 5
    
    db ck;
    cin >> ck;
    // vector<pair<int, int>> qt;
    vector<db> a(8);
    db qt = 0;
    for(int i=0; i<8; i++){
        cin >> a[i];
        if(i%2 != 0){
            if(a[i] == 0){
                qt += a[i-1];
            }else{
                qt += 0;
            }
        }
    }
    db res = (db)(qt/4.0)*0.4 + (db)ck*0.6;
    if(res >= 4.75){
        cout << "passed";
    }else{
        cout << "failed";
        
    }
    return 0;
}