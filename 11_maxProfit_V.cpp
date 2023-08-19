// description: with fee

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(int fee, vector<int> &prices)
    {
        if (prices.size() == 1 || prices.empty())
            return 0;
        int maxProf = 0, buy = prices[0] + fee;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] + fee < buy)
            {
                buy = prices[i] + fee;
            }
            else if (prices[i] > buy)
            {
                maxProf += prices[i] - buy;
                buy = prices[i];
            }
        }
        return maxProf;
    }
};

int main()
{
    std::vector<int> a = {1, 3, 2, 8, 4, 9};
    Solution sl;
    int prof = sl.maxProfit(2, a);
    std::cout << prof << std::endl;
    return 0;
}