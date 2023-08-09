#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2,int n) {
        for(int i = 0; i<n ; i++){

            nums1[m+i] = nums2[i];
        }
        std::sort(nums1.begin(),nums1.end());
    }
};

/*class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2,int n) {
        int i = nums1.size();
        while(n>0){
            if(m>0 && nums1[m-1]>nums2[n-1]){
                nums1[i-1] = nums1[m-1];
                m--;
                i--;
            }else{
                nums1[i-1] = nums2[n-1];
                n--;
                i--;
            }
        }
    }
};*/ //richtig loesung


int main(){
    std::vector<int> nums1 = {1,2,3,0,0,0};
    std::vector<int> nums2 = {2,5,6};
    Solution sul;
    sul.merge(nums1,3, nums2,nums2.size());
    for(auto ele : nums1){
        std::cout<<ele<<" ";
    }
     std::cout<<std::endl;
    return 0;
}