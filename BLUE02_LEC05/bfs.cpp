#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define MAX 100 // MAX VERTICES
int V, E;
bool visited[MAX];
int path[MAX];
vector<int> graph[MAX];

void BFS(int s){
    for(int i=0; i < V; i++){
        visited[i] = false; // All visited vertice  = false
        path[i] = -1; // path = false
    } 
    queue<int> q; // Dung de chua cac dinh ke voi dinh da xet
    visited[s] = true; // Phan tu dau tien da duoc visit 
    q.push(s); // Luu phan tu dau tien vao queue
    while(!q.empty()){
        // Khi queue chua rong =>
        int u = q.front(); // Lay phan tu dau tien trong queue ra xet (0)
        q.pop(); // lay ra roi thi xoa no di
        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v); // Dua v vao queue de xet
                path[v] = u; // Dinh v da duoc u visit
            }
        }
    }
}

void printPath(int s, int f){
    // 0 1 2 3 4 5
    //-1 0 1 0 3 1
    int b[MAX];
    int m = 0;
    if(f == s){
        cout << f;
        return;
    }
    if(path[f] == -1){
        cout << "no path";
        return;
    }
    while(true){
        b[m++] = f; //b[1   ] = 5; //2. b[2] = 1
        f = path[f]; // f = path[f] = path[5] = 1;// 2. f = path[1] = 0
        if(f == s){
            b[m++] = s; //b[3] = 0;
            break;
        }
    }
    for(int i=m-1; i>=0; i--){
        cout << b[i] <<" ";
    }
    // 0 -> 1 -> 5
}

void printRecursion(int s, int f){
    if(s == f){
        cout << f << " ";
    }else{
        if(path[f] == -1){
            cout <<"no path"<<endl;
        }else{
            printRecursion(s, path[f]);
            cout << f <<" ";
        }
    }
    //1. fun(0, 1) -> fun(0, 0) -> 0 5
    //2. fun(0, )
}

int main(){
        int u, v;
        cin >> V >> E;
        for(int i=0; i < E; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int s = 0;
        int f = 5;
        BFS(s);
        printPath(s, f);
        return 0;   
}
