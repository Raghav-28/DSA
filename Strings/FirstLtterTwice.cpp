// LEETCODE 2351

class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.length();
        unordered_map<char , int> mp;

        for(auto &ch : s){
            mp[ch]++;
            if(mp[ch]==2){
                return ch;
            }
        }
        return '0';
    }
};