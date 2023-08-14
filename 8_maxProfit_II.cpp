#include <iostream>
#include <vector>

// greedy algorithm:
//  class Solution{
//      public:
//      int maxProfit(std::vector<int>& prices) {
//          if(prices.empty() || prices.size() == 1) return 0;
//          int maxProf = 0;
//          for(int i = 1; i<prices.size(); i++){
//              if(prices[i] > prices[i-1]){
//                  maxProf += prices[i] - prices[i-1];
//              }
//          }
//          return maxProf;

//     }
// };

// dynamic programming
class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        if (prices.empty() || prices.size() == 1)
            return 0;
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }
        return dp[n - 1][0];
    }
};

int main()
{
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    Solution sl;
    int prof = sl.maxProfit(a);
    std::cout << prof << std::endl;
    return 0;
}