//LEETCODE 1863
//APPROACH-1
class Solution {
    public:
    
        int solve(vector<int>&nums, int i,int Xor){
            if(i== nums.size()){
                return Xor;
            }
            int include = solve(nums, i+1, nums[i]^Xor);
           
            int exclude = solve(nums, i+1,Xor);
            return include + exclude;
        }
    
    
        int subsetXORSum(vector<int>& nums) {
            return solve(nums,0,0);
    
        }
    };
//APPROACH-2
class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int n = nums.size();
    
            int result =0;
            for(int &num: nums){
                result |= num;
            }
            return result << (n-1);
        }
    };