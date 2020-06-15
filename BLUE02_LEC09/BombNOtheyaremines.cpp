#include<bits/stdc++.h>
using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
int n,m;

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int BFS(pair<int,int> s, pair<int,int> t, vector<vector<bool> > &bombs){

    queue<pair<pair<int,int>, int> > Q;
    Q.push({s,0});

    bombs[s.first][s.second] = 1;
    
    while(!Q.empty()){
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int c = Q.front().second;
        
        Q.pop();
        
        if(x == t.first && y == t.second) return c;
        
        for(int i = 0; i < 4; i++){
            int xt = x + dx[i];
            int yt = y + dy[i];
            
            if(isValid(xt, yt) && !bombs[xt][yt]){
                bombs[xt][yt] = 1;
                Q.push({{xt,yt}, c + 1});
            }
        }
    }
}

int main(){
    while( cin >> n >> m && n + m){
        int r, c, t, rt; 
        cin >> r;
        vector<vector<bool> > board(n,vector<bool>(m,0));
        for(int i = 0; i < r; i++){
            cin >> rt >> c;
            for(int j = 0; j < c; j++){
                cin >> t;
                board[rt][t] = 1;
            }
        }
        
        pair<int,int> s, f;
        cin >> s.first >> s.second;
        cin >> f.first >> f.second;
        cout << BFS(s, f, board) << endl;
    }
}