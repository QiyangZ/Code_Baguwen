#include<iostream>
#include<vector>

using namespace std;

// can still be optimized, L,R are actually not necessary, we can know the left and right
// product in advance, and initialize them at the very beginning and then use index to 
// give them value. so that the space complexity can be optimized.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProdu = {1};
        vector<int> rightProdu = {1};
        vector<int> answer;
        int L=1,R=1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            L = nums[i-1]*L;
            leftProdu.emplace_back(L);
        }

        for(int i=1; i<n; i++){
            R = R*nums[n-i];
            rightProdu.emplace_back(R);
        }
        rightProdu.emplace_back(1);


        for(int i = 0; i<n ;i++){
            answer.emplace_back(leftProdu[i] * rightProdu[n-1-i]);
        }

        return answer;
    }
};

int main(){
    Solution sl;
    vector<int> nums = {1,2,3,4};
    vector<int> answer = sl.productExceptSelf(nums);
    for(int i=0; i<nums.size(); i++){
        cout<<answer[i]<<" ";
    }

    return 0;
}