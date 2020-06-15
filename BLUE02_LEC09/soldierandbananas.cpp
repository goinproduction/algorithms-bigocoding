#include<bits/stdc++.h>
using namespace std;
int main(){
    int k, n, w;
    cin >> k >> n >> w;
    long long dollar_need = 0;  
    for(int i=1; i<=w; i++){
        dollar_need += i*k;
    }
    if(n >= dollar_need){
        cout << "0" <<endl;
    }else{
        long long res = dollar_need - n; 
        cout << res;
    }
    return 0;
}