#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el endl
int main(){
    ll n;
    cin >> n;
    int c_500 = 0, c_200 = 0, c_100 = 0, c_50 = 0, c_20 = 0, c_10 = 0;
    while(n > 0){
        if(n >= 500){
            c_500 += n/500;
            cout <<"500 "<< c_500 << el;    
            n %= 500;
        }
        if(n < 500 && n >= 200){
            c_200 += n/200;
            cout <<"200 "<< c_200 << el;
            n %= 200;
        }
        if(n < 200 && n >= 100){
            c_100 += n/100;
            cout <<"100 "<< c_100 << el;
            n %= 100;
        }
        if(n >= 50 && n < 100){
            c_50 += n/50;
            cout <<"50 "<< c_50 << el;
            n %= 50;
        }
        if(n >= 20 && n < 50){
            c_20 += n/20;
            cout <<"20 "<< c_20 << el;
            n %= 20;
        }
        
        if(n >= 10 && n < 20){
            c_10 += n/10;
            cout <<"10 "<< c_10 << el;
            n %= 10;
        }
    }    
}