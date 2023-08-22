// Online C++ compiler to run C++ program online
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int longestPalindrome(string s){
        vector<int> quanti;
        int n = s.length();
        for(int i=1; i<=n/2; i++){
            int left = i-1;
            int right =i+1;
            int count = 0;
            if(s[left] == s[i] && s[right] != s[i]){
                right = i;
                while(left>=0 && right<=n-1){
                    if(s[left] == s[right]){
                    left--;
                    right++;
                    count += 2;
                    }
                }
            }else if(s[right] == s[i] && s[left] != s[i]){
                left = i;
                while(left>=0 && right<=n-1){
                    if(s[left] == s[right]){
                    left--;
                    right++;
                    count += 2;
                    }
                }
            }else{
                 while(left>=0 && right<=n-1){
                    if(s[left] == s[right]){
                    left--;
                    right++;
                    count += 2;
                    }
                }
                count +=1;
            }

            quanti.push_back(count);
        
        }
        return *max_element(quanti.begin(), quanti.end());
    }
};

// class Solution {
// public:
//     int longestPalindrome(string s) {
//         int n = s.length();
//         int maxLen = 0;

//         for (int i = 0; i < n/2; i++) {
//             int left = i;
//             int right = i;
//             while (left >= 0 && right < n && s[left] == s[right]) {
//                 maxLen = max(maxLen, right - left + 1);
//                 left--;
//                 right++;
//             }
//         }

//         return maxLen;
//     }
// };

int main(){
    string s = "babad";
    Solution sol;
    int longti = sol.longestPalindrome(s);
    cout<<"answer is: "<< longti<<endl;
    return 0;
}