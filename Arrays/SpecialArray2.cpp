//Problem leetcode 3152

//APPROACH 1 MINE PASSED 535/536 CASES
class Solution {
    public:
        void solve(vector<int>& nums, int i , int j, vector<bool>& answer) {
            for (int k = i; k < j; ++k) {
                if ((nums[k] % 2) == (nums[k + 1] % 2)) {
                    answer.push_back(false);
                    return;
                }
            }
            answer.push_back(true);
        }
    
        vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
            vector<bool> answer;
            for (auto &query : queries) {
                int i = query[0], j = query[1];
                solve(nums, i, j, answer);
            }
            return answer;
        }
    };

//APPROACH 2 OPTIIZED
class Solution {
    public:
        vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            vector<int> prefix(n, 0); 
            
            
            for (int i = 1; i < n; i++) {
                prefix[i] = prefix[i - 1];
                if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
                    prefix[i]++;
                }
            }
    
            vector<bool> ans; 
            
            for (auto& q : queries) {
                int left = q[0], right = q[1];
                int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
                ans.push_back(specialCount == 0);
            }
    
            return ans; 
        }
    };