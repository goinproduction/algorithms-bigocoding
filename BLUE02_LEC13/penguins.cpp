#include <bits/stdc++.h> 
  
using namespace std; 
  
int n; 
map <string , int> mymap; 
string s; 
  
int main () {
    cin >> n; 
  
    cin.ignore(); 
  
    while (n--) {
        getline(cin , s); 
        mymap[s]++; 
    }
  
    string res; 
    int maxi = -1; 
  
    for (map <string , int> :: iterator it = mymap.begin(); it != mymap.end(); it++) 
        if (maxi < it->second) {
            maxi = it->second; 
            res = it->first; 
        }
  
    cout << res; 
    return 0; 
}