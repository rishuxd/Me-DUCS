// distance vector routing

// what makes it better then dijkstra
/* Negetive edges
    -> it wil work for edges and negative cycles 
    -> it can detect negative cycles as well  */

#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9;

int main(){
    int n,m;cin>>n>>m;
    // 5 8
    vector<vector<int>> edges;
    for(int i =0 ; i<m ; i++){
        int u,v,w;
/*      1 2 3
        3 2 5
        1 3 2
        3 1 1
        1 4 2
        0 2 4
        4 3 -3
        0 1 -1 */
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src;cin>>src;
    vector<int> dist(n,INF);
    dist[src] =  0;
    for( int it = 0 ; it < n-1 ; it++){
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v],w+dist[u]);
        }
    }
    for( auto i : dist)
        cout<<i<<" ";
    cout<<"\n";
}