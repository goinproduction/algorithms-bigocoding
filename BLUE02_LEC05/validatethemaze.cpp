#include<iostream>
#include<vector>
#include<string>    
#include<queue>
using namespace std;
#define MAX 21

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

string maze[MAX];
bool visited[MAX][MAX]; 
int n, m;

struct loc{
  int r, c;  
};

// con nam trong me cung
bool isValid(int r, int c){
    return (r >= 0 && r < n && c >= 0 && c < m);
}

bool BFS(loc s, loc f){
    queue<loc> q;
    visited[s.r][s.c] = true;
    q.push(s);
    
    while(!q.empty()){
        loc u = q.front();
        q.pop();
        
        if(u.r == f.r && u.c == f.c){
            return true;
        }
        
        // len xuong trai phai
        for(int i = 0; i<4; i++){
            
            int r = u.r + dr[i];    
            int c = u.c + dc[i];
        
            if(isValid(r, c) && maze[r][c]== '.' && !visited[r][c]){
            visited[r][c] = true;
            q.push((loc) {r, c});
            }
        }
    }
    return false;
}   

int main(){
    /*      2
            4 4
            ####
            #...
            #.##
            #.##
            5 5
            #.###
            #..##
            ##..#
            #.#.#
            ###.# 
    */
    int Q;
    cin >> Q;
    while(Q--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> maze[i];
        }
        vector<loc> entrance; // 2 diem vao va ra cua me cung
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                visited[i][j] = false;
                if(maze[i][j] == '.' && (i==0 || j==0 || i==n-1 || j == m-1 )){
                    entrance.push_back((loc){i,j});
                }
            }
        }
        // maze chi co duy nhat 1 diem vao 1 diem ra
        if(entrance.size() != 2){
            cout << "invalid" << endl;
        }else{
            loc s = entrance[0];
            loc f = entrance[1];
            cout << (BFS(s, f) ? "valid":"invalid") << endl;
        }
    }
}
