// dijkstra

#include "bits/stdc++.h"
using namespace std;

const int inf = 1e7;

int main(){
    // vertices , edges = 4,4
    int n, m; cin>>n>>m;

    vector<int>dist(n+1,inf);
    vector<vector<pair<int,int>>> graph(n+1);

    for( int i =0 ; i<m  ; i++){
        // adjacent edges , weight
        int u,v,w;
        // 1 2 24
        // 1 4 30
        // 3 1 3
        // 4 3 12
    
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w}); // if graph is undirected

/*      (2,24)  (4,30)  (1,3)
        (1,24)
        (1 ,3)  (4,12)
        (1,30)  (3,12) */

    }

    int source;cin>>source; // 1
    dist[source] = 0;
    
    // {weight,vertex}
    set<pair<int,int>> s;

    s.insert({0,source});

    while(!s.empty()){

        // smallest distance
        auto x = *(s.begin());
        s.erase(x);
        for(auto it : graph[x.second]){
            if(dist[it.first] > dist[x.second]+ it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }

    for(int i=1 ; i<=n ; i++){
        if(dist[i]<inf){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<-1<<" ";
        }
    }
}