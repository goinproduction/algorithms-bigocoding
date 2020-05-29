#include<bits/stdc++.h>
using namespace std;
#define MAX 501

const int INF = 1e9 + 7;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);

void Dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        
        int u = top.first; 
        int w = top.second;
        
        for(pair<int, int> &nb: graph[u]){
            if(w + nb.second < dist[nb.first]){
                dist[nb.first] = w + nb.second;
                pq.push(make_pair(nb.first, dist[nb.first]));
            }
        }
    }
}
int main(){
    int N, A, B, W;
    cin >> N;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
    for(int i = 0; i < N; i++){
        cin >> A >> B >> W;
        graph[A].push_back(make_pair(B, W));
        graph[B].push_back(make_pair(A, W));
    }
    
    int S, Q, V;
    cin >> S;
    Dijkstra(S);
    cin >> Q;
    while(Q--){
        cin >> V;
        if(dist[V] != INF){
            cout << dist[V] << endl;
        }else{
            cout <<"NO PATH"<< endl;
        }
    }
    
}
