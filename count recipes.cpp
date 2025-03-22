// PROBLEM 2115 LEETCODE

// BRUTE FORCE
class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            
            int n = recipes.size();
            vector<string> result;
    
            unordered_set<string> st(begin(supplies),end(supplies));
    
            vector<bool> cooked(n,false);
    
            int count =n;
            while(count--){
                for(int j=0;j<n;j++){
                    if(cooked[j]){
                        continue;
                    }
                    bool banega = true;
                    for(int k=0;k<ingredients[j].size();k++){
                        if(!st.count(ingredients[j][k])){
                            banega = false;
                            break;
                        }
    
                    }
                    if(banega){
                        st.insert(recipes[j]);
                        result.push_back(recipes[j]);
                        cooked[j]= true;
                    }
                }
            }
            return result;
        }
    };

    // USING TOPOLOGICAL SORT
    class Solution {
        public:
            vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
                int n = recipes.size();
                unordered_set<string> st(begin(supplies),end(supplies));
        
                unordered_map<string, vector<int>> adj;
                
                vector<int> indegree(n,0);
                for(int i=0;i<n;i++){
                    for(string &ing: ingredients[i]){
                        if(!st.count(ing)){
                            adj[ing].push_back(i);
                            indegree[i]++;
                        }
                    }
                }
        
                queue<int> que;
                for(int i=0;i<n;i++){
                    if(indegree[i]==0){
                        que.push(i);
                    }
                }
                vector<string> result;
                while(!que.empty()){
                    int i= que.front();
                    que.pop();
                    string recipe = recipes[i];
                    result.push_back(recipe);
        
                    for(int & idx: adj[recipe]){
                        indegree[idx]--;
                        if(indegree[idx]==0){
                            que.push(idx);
                        }
                    }
                }
                return result;
            }
        };