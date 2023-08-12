#include<vector>
#include<iostream>
#include<algorithm> //for sort()
#include<unordered_map>


// class Solution {
// public:
//     int majorityElement(std::vector<int>& nums) {
//         std::sort(nums.begin(),nums.end());
//         return nums[nums.size()/2];

//     }
// };
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int,int> count;
        int ele = 0, cou = 0;
        for(auto num:nums){
            ++count[num];
            if(count[num] > nums.size()/2){
                ele = num;
                cou = count[num];
            }
        }
        return ele;

    }
};



int main(){
    std::vector<int> a = {2,2,1,1,1,2,2};
    Solution sl;
    int ele = sl.majorityElement(a);
    std::cout<<ele<<std::endl;
    return 0;
}
