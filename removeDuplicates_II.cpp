#include<iostream>
#include<vector>

class Solution{
    public:
    int removeDuplicates(std::vector<int>& nums){
        std::vector<int>::iterator pos = nums.begin();
            if (nums.end()-2 > pos){
                while(pos != nums.end()-2){
                    if(*pos == *(pos+2)){
                    pos = nums.erase(pos);
                    }else{
                    pos++;
                    }
                }
            }else{}
        return nums.size();
    }
};

int main(){
    std::vector<int> nums = {1,1,1,2,2,3,4,5};
    Solution sl;
    int len = sl.removeDuplicates(nums);
    for(auto ele:nums){
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
    std::cout<<len<<std::endl;
    return 0;
}