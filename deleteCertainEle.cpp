#include <vector>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int>::iterator pos = nums.begin();
        while(pos != nums.end()){
            if(val == *pos){
                pos = nums.erase(pos);
            }else{
                pos++;
            }
        }
        return nums.size();
    }
    
};

int main(){
    std::vector<int> a = {3,2,2,3};
    Solution sl;
    int len = sl.removeElement(a,3);
    for(auto ele: a){
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
    std::cout<<len<<std::endl;
    return 0;
}

// a wrong while-loop:
//  while(pos != nums.end()){
//             if(val == *pos){
//               nums.erase(pos);
//             }
//             pos++;
//         }
//this is not correct because after erase(), the pos will be invaulid. 
//To solve this problem ,you use the return of erase, it will point to the next iterator.

// description:
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。