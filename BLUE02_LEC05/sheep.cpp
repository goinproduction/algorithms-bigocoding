#include<iostream>
#include<queue>
using namespace std;

#define MAX 501
string backyard[MAX];
int n, m;
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int numSheeps = 0, numWolves = 0;

struct loc{
    int r, c;
};

bool isValid(int r, int c){
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void BFS(loc s){
    queue<loc> q;
    q.push(s);  
    
    int sheeps = backyard[s.r][s.c] == 'k';
    int wolves = backyard[s.r][s.c] == 'v';
    backyard[s.r][s.c] ='#';
    bool escapse = false;
    while(!q.empty()){
        loc u = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            
            if(!isValid(r, c)){
                escapse = true; //=> da chay ra khoi backyard
                continue;
            }
            if(backyard[r][c] != '#'){
                sheeps += backyard[r][c] == 'k';
                wolves += backyard[r][c] == 'v';
                backyard[r][c] = '#';
                q.push((loc){r, c});
            }
        }
    }
    if(escapse){
        numSheeps += sheeps;
        numWolves += wolves;
    }else{
        sheeps > wolves ? numSheeps += sheeps: numWolves += wolves;
    }
}
int main(){
    /*
     8 8
    .######.
    #..k...#
    #.####.#
    #.#v.#.#
    #.#.k#k#
    #k.##..#
    #.v..v.#
    .######.
     
     */
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> backyard[i];
    }
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(backyard[i][j] != '#'){
                BFS((loc){i, j});
            }
        }
    }
    cout << numSheeps <<" "<<numWolves<<endl;
    return 0;
}
