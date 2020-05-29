#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define MAX 1001

int V, E;
vector<int> graph[MAX];
bool visited[MAX];
int path[MAX];

void DFS(int val){
    stack<int> q;
    q.push(val);
    visited[val] = true;
    while(!q.empty()){
        int u = q.top();
        q.pop();
        for(int i=0; i<graph[u].size(); i++){
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
    int n, u, v;
    cin >> V;
    E = V - 1;
    for(int i=0; i<E; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(1);
    int res = 0;
    int min_path = MAX;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> u;
        if(path[u] < min_path || (path[u] == min_path && u < res)){
            min_path = path[u];
            res = u;
        }
    }
    cout << res;
} 
