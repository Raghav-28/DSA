// PROBLEM 2685 LEETCODE
// USING DFS

class Solution {
public:

    void dfs(int i,  unordered_map<int, vector<int>>& adj, vector<bool> &visited , int &v, int &e){
        visited[i] = true;
        v++;
        e += adj[i].size();

        for(int &neigh: adj[i]){
            if(!visited[neigh]){
                dfs(neigh, adj, visited, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int result =0;

        for(auto &edge : edges){
            int u= edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            if(visited[i]== true){
                continue;
            }
            int v= 0;
            int e=0;
            dfs(i,adj,visited,v,e);

            if((v*(v-1)) == e){
                result++;
            }
        }
        return result;
    }
};

// USING BFS

class Solution {
    public:
    
        void bfs(int i, unordered_map<int,vector<int>> &adj, vector<bool> &visited, int &v, int &e){
            queue<int> que;
            que.push(i);
            visited[i]= true;
    
            while(!que.empty()){
                int curr = que.front();
                que.pop();
                v++;
                e += adj[curr].size();
    
                for(int &neigh : adj[curr]){
                    if(!visited[neigh]){
                        visited[neigh]= true;
                        que.push(neigh);
                    }
                }
            }
        }
       
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            unordered_map<int, vector<int>> adj;
            int result =0;
    
            for(auto &edge : edges){
                int u= edge[0];
                int v = edge[1];
    
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            vector<bool> visited(n,false);
    
            for(int i=0;i<n;i++){
                if(visited[i]== true){
                    continue;
                }
                int v= 0;
                int e=0;
                bfs(i,adj,visited,v,e);
    
                if((v*(v-1)) == e){
                    result++;
                }
            }
            return result;
        }
    };

    //USING DSU
    class Solution {
        public:
            class DSU {
                public:
                vector<int> parent;
                vector<int> size;
        
                DSU(int n ){
                    parent.resize(n);
                    size.resize(n);
        
                    for(int i=0;i<n;i++){
                        parent[i]=i;
                        size[i]=1;
                    }
        
                }
                int find(int x){
                    if(parent[x]== x){
                        return x;
                    }
                    return parent[x] = find(parent[x]);
                }
        
                void Union(int x, int y){
                    int x_parent = find(x);
                    int y_parent = find(y);
        
                    if(x_parent == y_parent){
                        return;
                    }
                    if(size[x_parent] > size[y_parent]){
                        parent[y_parent]= x_parent;
                        size[x_parent] += size[y_parent];
                    }
                    else if(size[x_parent] < size[y_parent]){
                        parent[x_parent]= y_parent;
                        size[y_parent] += size[x_parent];
                    } 
                    else{
                        parent[x_parent] = y_parent;
                        size[y_parent] += size[x_parent];
                    }
                }
            };
            int countCompleteComponents(int n, vector<vector<int>>& edges) {
                DSU dsu(n);
                unordered_map<int, int> mp;
        
                for(auto &edge : edges){
                    int u= edge[0];
                    int v= edge[1];
                    dsu.Union(u,v);
                }
        
                for(auto &edge: edges){
                    int u = edge[0];
                    int v = edge[1];
        
                    int root = dsu.find(u);
                    mp[root]++;
                }
        
                int result =0;
                for(int i=0;i<n;i++){
                    if(dsu.find(i)==i){
                        int v = dsu.size[i];
                        int e= mp[i];
        
                        if((v*(v-1))/2 == e){
                            result++;
                        }
                    }
                }
                return result;
            }
        };