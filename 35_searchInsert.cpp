#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int middle;
        while(left <= right){
            middle = left + (right - left)/2;
            if(nums[middle] < target){
                left = middle + 1;
            }else right = middle - 1;
        }

    return left;
    }
};

int main(){
    vector<int> nums = {1,3,5,7,9};
    Solution sol;
    int Pos = sol.searchInsert(nums, 5);
    cout<<Pos<<endl;
    return 0;
}