#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSumv2(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> resultList;

    for (int i = 0; i < nums.size(); i++) {
        int d = target - nums[i];
        for (int j = i + 1, k = nums.size() - 1; j < nums.size(); j++) {
            while (j < k && (nums[j] + nums[k]) > d) {
                k--;
            }
            if (j == k) {
                break;
            }
            if (nums[j] + nums[k] == d) {
                resultList.push_back({ nums[i], nums[j], nums[k] });
            }
            
        }
    }
    return resultList;
}

int main() {
    std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    std::vector<std::vector<int>> resultList = threeSumv2(nums, 0);

    for (const auto& list : resultList) {
        std::cout << "[";
        for (const auto& num : list) {
            std::cout << num << ", ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
