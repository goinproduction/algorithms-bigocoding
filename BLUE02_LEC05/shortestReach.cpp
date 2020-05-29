#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1001
int path[MAX];
bool visited[MAX];
vector<int> graph[MAX];
int V, E;

void BFS(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                path[v] = path[u] + 1;
            }
        }
    }
}
int main(){
    int Q, u, v, s;
    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> V >> E;
        for(int i = 0; i < MAX; i++){
            graph[i].clear();   
            visited[i] = false;
            path[i] = 0;
        }
        for(int i = 0; i < E; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        cin >> s;
        BFS(s);
        
        for(int i=1; i <= V; i++){
            if(i == s){
                continue;
            }
            if(visited[i]){
                cout << path[i]*6 <<" ";
            }else{
                cout << "-1"<<" ";
            }
        }
        cout << endl;
    }
    return 0;
}
