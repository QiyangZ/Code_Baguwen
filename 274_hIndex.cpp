#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:
    int hIndex(vector<int>& citations){
        if(citations.size() == 1 && citations[0]>0) return 1;
        sort(citations.begin(),citations.end());
        for(int i = citations.size()-1; i>=0; i--){
            if(citations.size()-i >= citations[i]) return citations[i];
        }
        return 0;
    }
};

int main(){
    vector<int> a = {3,0,6,1,5};
    Solution sl;
    int ans = sl.hIndex(a);
    std::cout << ans << std::endl;
    return 0;
}