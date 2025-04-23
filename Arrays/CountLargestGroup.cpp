//LEETCODE PROBLEM 1399

class Solution {
    public:
    
        int findDigitsSum(int num){
            int sum =0;
            while(num >0){
                sum += num%10;
                num /= 10;
            }
            return sum;
        }
    
        int countLargestGroup(int n) {
            unordered_map<int,int> mp;
    
            int count =0;
            int maxSize =0;
            
            for(int i=1; i<=n ; i++){
                int digitSum = findDigitsSum(i);
    
                mp[digitSum]++;
                if(mp[digitSum]== maxSize){
                    count++;
                } else if(mp[digitSum] > maxSize){
                    maxSize = mp[digitSum];
                    count =1;
                }
            }
            return count;
        }
    };