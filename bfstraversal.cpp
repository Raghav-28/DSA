#include<bits/stdc++.h>
using namespace std;


void DFStraversal(vector<vector<int>> & adj, vector<bool> & visited ,int s){
    visited[s]= true;

    cout<<s<<" ";
    for(auto &v:adj[s]){
        if(visited[v]== false){
            DFStraversal(adj,visited,v);
        }
    }
}

void DFS(vector<vector<int>> & adj, int s){
    vector<bool> visited(adj.size(), false);
    DFStraversal(adj,visited,s);
}


int main(){
    int V =5;
    vector<vector<int>> adj(V);

    vector<vector<int>> edges = {{1,2},{1,0},{2,0},{2,3},{2,4}};

    for(auto &e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    for(int i=0;i<V;i++){
        int s= i;
        cout<<"DFS FROM SOURCE"<<s<<endl;
    DFS(adj,s);
    }

    return 0;
}