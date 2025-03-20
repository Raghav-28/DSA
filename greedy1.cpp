#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoins(vector<int> &coins, int amount) {
    int n = coins.size();
    sort(coins.begin(), coins.end());
    int res = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(amount >= coins[i]) {
          
            int cnt = (amount / coins[i]);
          
            res += cnt;
          
            amount -= (cnt * coins[i]);
        }
      
        if(amount == 0)
            break;
    }
    return res;
}

int main() {
    vector<int> coins = {5, 2, 10, 1};
    int amount = 39;
  
    cout << minCoins(coins, amount);
    return 0;
}