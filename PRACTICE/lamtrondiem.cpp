#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
int main(){
    db n, p_res;
    cin >> n;
    if((double(n) - int(n)) >= 0 && (double(n) - int(n)) < 0.25)
        p_res = (int)n;
    else if((double(n) - int(n)) >= 0.25 && (double(n) - int(n)) < 0.75)
        p_res = (int)n + 0.5;
    else
        p_res = (int)n + 1.0;
    cout << fixed << setprecision(1) << p_res;
}