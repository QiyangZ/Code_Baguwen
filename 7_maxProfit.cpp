#include <iostream>
#include <vector>
#include <algorithm>

// 暴力解法：
//  class Solution {
//  public:
//      int maxProfit(std::vector<int>& prices) {
//          std::vector<int> profits;
//          int profit;
//          for(int i=prices.size()-1; i>=0; i--){
//              for(int j=i-1; j>=0; j--){
//                  profit = prices[i] - prices[j];
//                  profits.push_back(profit);
//              }
//          }
//          std::sort(profits.begin(),profits.end());
//          if(*(profits.end()-1) <= 0){
//              return 0;
//          }else{
//              return *(profits.end()-1);
//          }
//      }
//  };

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int minPrice = 1e9, maxProf = 0;
        for (int ele : prices)
        {
            minPrice = std::min(ele, minPrice);
            maxProf = std::max(maxProf, ele - minPrice);
        }
        return maxProf;
    }
};

int main()
{
    std::vector<int> a = {7, 6, 4, 3, 1};
    Solution sl;
    int prof = sl.maxProfit(a);
    std::cout << prof << std::endl;
    return 0;
}
