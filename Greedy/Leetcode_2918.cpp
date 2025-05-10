// LEETCODE 2981. 
// MINIMUM EQUAL SUM OF TWO ARRAYS AFTER REPLACING ALL ZEROS

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        long long zero_1 =0; // number of zeros in nums1
        long long zero_2 =0; // number of zeros in nums2

        for(auto &num :nums1){
            sum1 += num == 0 ? 1 : num;
            zero_1 += num == 0 ? 1 : 0;
        }

        for(auto &num: nums2){
            sum2 += num == 0 ? 1 : num;
            zero_2 += num == 0? 1: 0;
        }

        if((sum1 < sum2 && zero_1 == 0) || (sum2 < sum1 && zero_2 ==0)){
            return -1;
        }
        return max(sum1,sum2);
    }
};