// description: maximal k trades
// if the preices is always going up, then ktrades-profit is equal to 1-trade-profits. The difference will apear when there are four(for instance) rises, but only one trade is allowed.
// so the increaces in the prices is very attension-worthy.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k == 0 || prices.empty())
            return 0;
        if (k > prices.size() / 2)
        {
            int maxProf = 0;
            for (int i = 1; i < prices.size(); i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    maxProf += prices[i] - prices[i - 1];
                }
            }
            return maxProf;
        }

        vector<int> buy(k, -1e7);
        vector<int> sell(k, 0);

        for (int i = 0; i < prices.size(); i++)
        {
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);

            for (int j = 1; j < k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k - 1];
    }
};

int main()
{
    std::vector<int> a = {3, 2, 6, 5, 0, 3};
    Solution sl;
    int prof = sl.maxProfit(7, a);
    std::cout << prof << std::endl;
    return 0;
}