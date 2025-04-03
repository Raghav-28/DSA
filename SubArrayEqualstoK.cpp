// PROBLEM LEETCODE 560
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n= nums.size();
            unordered_map<int, int> mp;
            mp.insert({0,1});
            int sum =0;
            int result =0;
            for(int i=0; i<n ;i++){
                sum += nums[i];
                if(mp.find(sum-k) != mp.end()){
                    result += mp[sum-k];
                }
                mp[sum]++;
            }
    
            return result;
        }
    };