//LEETCODE 3341
// intresting one as i 1st use the greedy but later i realise its not worth it then after finding some solutions and watching video i found that its can be solved using graph

class Solution {
    public:
        vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
        typedef pair<int,pair<int,int>> P;
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int m = moveTime.size();
            int n = moveTime[0].size();
    
            vector<vector<int>> result(m,vector<int>(n,INT_MAX));
            priority_queue<P,vector<P>,greater<P>> pq;
    
    
            result[0][0]=0;
            pq.push({0,{0,0}});
    
            while(!pq.empty()){
                int currTime = pq.top().first;
                auto cell = pq.top().second;
    
                int i= cell.first;
                int j = cell.second;
    
                pq.pop();
                if(i== m-1 && j==n-1){
                    return currTime;
                }
    
                for(auto & dir : directions){
                    int i_ = i+dir[0];
                    int j_ = j+dir[1];
    
                    if(i_ >= 0 && i_ <m && j_ <n && j_ >=0){
                        int wait =max(moveTime[i_][j_] - currTime,0);
                        int arrTime = currTime + wait + 1;
    
                        if(result[i_][j_] > arrTime){
                            result[i_][j_]= arrTime;
                            pq.push({arrTime,{i_,j_}});
                        }
                    }
                }
            }
            return result[m-1][n-1];
        }
    };