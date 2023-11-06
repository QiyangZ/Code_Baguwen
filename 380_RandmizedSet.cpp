#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(0)); // (unsigned)--> to cast type / the number of seconds from 1970
    }
    
    bool insert(int val) {
        if(uMap.count(val)) return false;
        int index = nums.size();
        nums.emplace_back(val);
        uMap[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if(!uMap.count(val)) return false;
        int index = uMap[val];
        int lastValu = nums.back();
        nums[index] = lastValu; 
        uMap[lastValu] = index;
        nums.pop_back();
        uMap.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand()%nums.size();
        return nums[index];
    }
private:
    std::unordered_map<int,int> uMap;
    std::vector<int> nums;
};

int main(){
    RandomizedSet randomizedSet = RandomizedSet();
    bool yi = randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    bool er = randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
    bool san = randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    int si = randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
    bool wu = randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    bool liu = randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
    int qi = randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
    std::cout<<yi<<" "<<er<<" "<<san<<" "<<si<<" "<<wu<<" "<<liu<<" "<<qi<<" "<<std::endl;
    return 0;
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */