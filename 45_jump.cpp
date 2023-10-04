#include<iostream>
#include<vector>
using namespace std;
// class Solution{
//     public:
//     int jump(vector<int> nums){
//         if(nums.size() == 1) return 0;
//         int counter = 0;
//         int temMax;
//         int currentPosi = 0;
//         for(int i=0; i< nums.size(); i++){
//             for(int j=0; j<=nums[i]; j++){
//                 nums[i]< nums[i+j] ? temMax = nums[i + j]: temMax = nums[i];
//             }
//             currentPosi += temMax;
//             counter++;
//             if(currentPosi >= nums.size() -1) return counter;
//         } here a while-loop is better, because when we jump, i is not continuously 

//         return nums.size();
//     }
//     }; 



int main(){
    vector<int> a = {0};
    Solution sl;
    int steps = sl.jump(a);
    std::cout << steps << std::endl;
    return 0;
}