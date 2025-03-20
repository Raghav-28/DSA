#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, int s) 
{
    queue<int> q;  
    
    vector<bool> visited(adj.size(), false);

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}


int main(){
    int V = 5;

    vector<vector<int>> adj(V);
vector<vector<int>> edges = {{1,2},{1,0},{2,0},{2,3},{2,4}};

     for(auto &e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    cout << "BFS starting from 0 : \n";
    bfs(adj, 0);
    return 0;
}