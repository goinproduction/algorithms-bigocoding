#include<iostream>
#include<stack>
using namespace std;
#define MAX 51
const int dr[] = {0, 0, 1, 1, 1,-1, -1, -1};
const int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};

int W, H, res;
char table[MAX][MAX];
int visited[MAX][MAX];
struct loc{
  int r, c;  
};
bool isValid(int r, int c){
    return (r >= 0 && r < H && c >= 0 && c < W);
}
int DFS(loc s){
    stack<loc> q;
    q.push(s);
    int count = 1;
    visited[s.r][s.c] = true;
    while(!q.empty()){
        loc u = q.top();
        q.pop();
        for(int i = 0; i < 8; i++){
            
            int r = u.r + dr[i];
            int c = u.c + dc[i];
        
            if(isValid(r, c) && table[r][c] - table[u.r][u.c] == 1 && (            visited[r][c] == 0)){
                q.push((loc){r,c}); 
                visited[r][c] = true;
                ++count;
            }
        }
    }
    return count;
}
int main(){
    
    /*
     
    4 3
    ABE
    CFG
    BDH
    ABC
    0 0

     */
    int T = 1;
    while(1){
        int t = 0;
        cin >> H >> W;
        if(H == 0 & W == 0){
            break;
        }
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin >> table[i][j];
                visited[i][j] = 0;
            }
        }
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(table[i][j] == 'A'){
                    res = max(t, DFS((loc){i,j}));
                }
            }
        }
        cout <<"Case "<< T++ << ": " << res << endl;
    }
}
