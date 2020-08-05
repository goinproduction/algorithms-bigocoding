#include<iostream>
using namespace std;

bool isPrime(int x){
    int k = 0;
    for (int i = 1; i <= x; i++)
    {
        if(x % i == 0){
            k++;
        }
    }
    if (k == 2)
    {
        return true;
    }
    
    
    return false;
}
int main(){
    int n, a[1005], count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[n];
        if(a[n] < 100 && isPrime(a[n])){
            count++;
        }
    }
    cout << count;
    return 0;
}