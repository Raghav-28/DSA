//PROBLEM  LEETCODE 3396
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            vector<bool> seen(128);
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (seen[nums[i]]) {
                    return i / 3 + 1;
                }
                seen[nums[i]] = true;
            }
            return 0;
        }
    };

    //MY APPROACH PASS TESTCASES 298/781
    class Solution {
        public:
            int minimumOperations(vector<int>& nums) {
                int n = nums.size();
                int i = 0, j = 0, ops = 0;
                unordered_map<int, int> mp;
        
                while(i < n) {
                    if(mp.count(nums[i])) {
                        for(int k = 0; k < 3 && j < n; k++) {
                            mp.erase(nums[j]);
                            j++;
                        }
                        ops++;
                    }else {
                        mp[nums[i]] = 1;
                        i++;
                    }
                }
        
                return ops;
            }
        };