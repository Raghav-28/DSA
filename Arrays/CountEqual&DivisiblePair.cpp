// PROBLEM LEETCODE 2176

//APPROACH 1 BRUTE FORCE
class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n = nums.size();
            int count=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(nums[i] == nums[j] && i*j %k == 0){
                        count++;
                    }
                }
            }
            return count;
        }
    };

//APPROACH 2
std::unordered_map<int, std::vector<int>> index_map;
    int count = 0;

    // Store indices for each unique number
    for (int i = 0; i < nums.size(); ++i) {
        index_map[nums[i]].push_back(i);
    }

    // For each list of indices with the same number
    for (const auto& [num, indices] : index_map) {
        int n = indices.size();
        // Iterate through all pairs (i, j)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((indices[i] * indices[j]) % k == 0) {
                    ++count;
                }
            }
        }
    }

    return count;