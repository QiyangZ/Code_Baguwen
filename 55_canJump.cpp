#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> nullPos;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                nullPos.push_back(i);
            }
        }

        if(nullPos.size() == 0){
            return true;
        }else{
            for(int j = 0; j<nullPos.size(); j++){
                int i = 1;
                while(i == nums[nullPos[j] - i] && i <= nullPos[j]) i++;
                if (i == nullPos[j]) return false;
            }
        }

        return true;
    }
};


int main(){
    vector<int> a = {2,3,1,1,4};
    Solution sl;
    bool judge = sl.canJump(a);
    std::cout<< judge <<std::endl;
    return 0;
}