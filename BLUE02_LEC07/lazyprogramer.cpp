#include<bits/stdc++.h>
using namespace std;

struct job{
    int a,b,d;
    job(){}
    bool operator < (job X)const{
        if(d != X.d) return d < X.d;
        return a > X.a;
    }
};

int main(){
    int t, n;
    cin >> t;
    
    while(t--){
        cin >> n;
        
        for(int i = 0;i < n;++i){
            cin >> job[i].a >> job[i].b >> job[i].d;
        }
        sort(job,job + n);
        
        priority_queue< pair<int, double> > q;
        pair<int, double> p;
        
        double t = 0, ans = 0, x;
        
        for(int i = 0;i < n;++i){
            t += job[i].b;
            q.push(make_pair(job[i].a,(double)job[i].b / job[i].a));
            
            while(t > job[i].d){
                p = q.top();
                q.pop();
                
                if(t - p.first * p.second > job[i].d){
                    t -= p.first * p.second;
                    ans += p.second;
                }else{
                    x = (t - job[i].d) / p.first;
                    t -= p.first * x;
                    ans += x;
                    q.push(make_pair(p.first, p.second - x));
                }
            }
        }
        cout << fixed << setpricision(2) << ans << endl;
    }
    return 0;
}
