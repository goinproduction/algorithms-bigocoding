#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
int main(){
    int a, b;
    cin >> a >> b;
    vector<pair<int, int>> t_pair;
    t_pair.push_back(make_pair(a, b));
    db res = sqrt(pow(t_pair[0].first, 2) + pow(t_pair[0].second, 2) + 2*sqrt(t_pair[0].first*t_pair[0].second));
    cout << fixed << setprecision(2) << res;
}