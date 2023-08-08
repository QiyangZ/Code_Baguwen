#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIndex;
    std::vector<std::vector<int>> resultList;
    
    for (int i = 0; i < nums.size(); i++) {
        int other = target - nums[i];
        if (numToIndex.find(other) != numToIndex.end()) {
            resultList.push_back({ numToIndex[other], i });
            // To prevent finding duplicate pairs, remove the element from the map
            numToIndex.erase(other);
        }
        numToIndex[nums[i]] = i;
    }
    
    return resultList;
}

int main() {
    std::vector<int> nums = { 5, 12, 6, 3, 9, 2, 1, 7 };
    std::vector<std::vector<int>> resultList = twoSum(nums, 13);

    for (const auto& list : resultList) {
        std::cout << "[" << list[0] << ", " << list[1] << "]" << std::endl;
    }

    return 0;
}
