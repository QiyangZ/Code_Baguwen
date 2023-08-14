#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        int buys1 = -nums[0], sells1 = 0;
        int buys2 = -nums[0], sells2 = 0;

        for (int i = 0; i < n; i++)
        {
            buys1 = max(buys1, -nums[i]);
            sells1 = max(sells1, buys1 + nums[i]);
            buys2 = max(buys2, sells1 - nums[i]);
            sells2 = max(sells2, buys2 + nums[i]);
        }

        return sells2;
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