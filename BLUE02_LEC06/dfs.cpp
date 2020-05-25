#include<iostream>
#include<stack>
#include<vector>
using namespace std;

#define MAX 100
int V, E;
bool visited[MAX];
int path[MAX];
vector<int> graph[MAX];

void DFS(int s){
    for(int i=0; i<V;        i++){
        visited[i] = false;
        path[i] = -1;
    }
    
    stack<int> q;
    visited[s] = true;
    q.push(s);
    
    
    while(!q.empty()){
        int u = q.top();
        q.pop();
        for(int i = 0; i< graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){        
                visited[v] = true;
                q.push(v);
                path[v] = u;
            }
        }
    }
}

void printPath(int s, int f){
    int m = 0;
    int b[MAX];
    if(s == f){
        cout << f;
        return;
    }
    if(path[f] == -1){
        cout <<"no path";
        return;
    }
    while(true){
        b[m++] = f;    
        f = path[f];
        if(f == s){
            b[m++] = s;
            break;
        }
    }
    for(int i=m-1; i>=0; i--){
        cout << b[i]<<" ";
    }
}

int main(){
    int u, v;
    cin >> V >> E;
    for(int i=0; i<V; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s=0, f=5;
    DFS(s);
    printPath(s,f);
    return 0;
}
