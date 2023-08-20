// max profit with frozen periods
#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        
        int n = prices.size();
        if(prices.empty() || n == 1) return 0;
        vector<int> buy(n, -1e7);
        vector<int> sell(n,0);

        buy[0] = -prices[0];
        buy[1] = max(-prices[1], -prices[0]);
        sell[1] = max(prices[1]-prices[0] , 0);
        
        for(int i = 2; i<n;i++){
            buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }
        return sell[n - 1];
    }
};

int main()
{
    std::vector<int> a = {1,2,3,0,2};
    Solution sl;
    int prof = sl.maxProfit(a);
    std::cout << prof << std::endl;
    return 0;
}