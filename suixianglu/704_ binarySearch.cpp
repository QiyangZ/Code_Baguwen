#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size() -1;
        int middle;
        while(left<=right){
            middle = left + (right - left)/2;
            if(nums[middle] > target){
                right = middle -1;
            }else if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[middle] == target){return middle;}
        }
        return -1;
    }
};

int main(){
    vector<int> a = {-1,0,3,5,9,12};
    int targ = 9;
    Solution sol;
    int tarIndex = sol.search(a,targ);
    cout<< "answer is: "<< tarIndex <<endl;
    return 0;
}