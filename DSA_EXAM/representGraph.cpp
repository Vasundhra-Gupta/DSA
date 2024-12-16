#include <iostream>
#include <vector>
using namespace std;
//O(v^2) O(v^2)
void adjMatrix(int n, int m){
    int adj[n][n] = {0};
    int u, v;
    cout<<"Enter Edges(0 based):\n";
    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }
}

//TC - O(V+ 2E)
//SC- O(V+ 2E)
// worst case , complete graph, e= v^2
void adjList(int n){
    vector<int> adj[n];
    int u, v;
    cout<<"Enter Edges (0 based):\n";
    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        cout<<i;
        for(int j=0; j< adj[i].size(); j++){
            cout<<"->"<<adj[i][j];
        }
        cout<<endl;
    }
}
//BFT AND DFT DONE ON LEETCODE!!
// make_pair(u, v) in case of weighted graph, while push

//0 based
int main(){
    cout<<"Vertices and Edges:\n";
    int n;
    int m;
    cin>>n>>m;
    adjMatrix(n, m);
    adjList(n);
    return 0;
}