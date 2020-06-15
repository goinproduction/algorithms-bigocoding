#include<bits/stdc++.h>
using namespace std;
int main(){

    char a;
    int n,cnt[26] = {0};
    bool check = true;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a >= 'A' && a <= 'Z'){
            a += 32;
        }
        if(a>='a' && a <= 'z'){
            cnt[a-97]++;
        }
    }
    for(int i = 0; i < 26; i++){
        if(cnt[i] == 0){
            check = false;
            break;
        }
    }
    if(!check){
        cout << "NO" << endl;
    }
    else{
         cout << "YES" << endl;
    }
    return 0;
}