#include<iostream>
#include<vector>
#include<algorithm> //for solution2
// class Solution {
// public:
//     void rotate(std::vector<int>& nums, int k) {
//         std::vector<int> new_num = nums;
//         int j = 0;
//         for(int i = nums.size() - k; i<nums.size(); i++){
//             new_num[j++] = nums[i];
//         }
//         for(int i =0; i<nums.size() - k; i++){
//             new_num[j++] = nums[i];
//         }
//         nums = new_num;
//     }
// };

// class Solution{
//     public:
//     void rotate(std::vector<int>& nums, int k){
//         std::reverse(nums.begin(),nums.end());
//         std::reverse(nums.begin(),nums.begin() + k);
//         std::reverse(nums.begin() + k, nums.end());
//     }
// };

class Solution{
    public:
    void reverse(std::vector<int> &nums, int start, int end){
        int interm;
        while(start < end){
            std::swap(nums[start++], nums[end--]);
        }
        }

    void rotate(std::vector<int>& nums, int k){
        k %= nums.size(); // 非常重要！！！
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    
};


int main(){
    std::vector<int> a = {1,2,3,4,5,6,7};
    Solution sl;
    sl.rotate(a,1);
    for(auto ele: a){
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
