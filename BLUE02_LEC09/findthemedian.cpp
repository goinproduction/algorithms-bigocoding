#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000005
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(n % 2 != 0){
        cout << (ll)a[n/2];
    }else{
        cout << (ll)(a[(n-1)/2] + a[n/2])/2;
    }
    return 0;
}