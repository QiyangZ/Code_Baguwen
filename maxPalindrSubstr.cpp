// Online C++ compiler to run C++ program online
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<utility>
using namespace std;


// return the lenth
// class Solution{
//     public:
//     int longestPalindrome(string s){
//         vector<int> quanti;
//         int n = s.length();
//         for(int i=1; i<=n/2; i++){
//             int left = i-1;
//             int right =i+1;
//             int count = 0;
//             if(s[left] == s[i] && s[right] != s[i]){
//                 right = i;
//                 while(left>=0 && right<=n-1){
//                     if(s[left] == s[right]){
//                     left--;
//                     right++;
//                     count += 2;
//                     }
//                 }
//             }else if(s[right] == s[i] && s[left] != s[i]){
//                 left = i;
//                 while(left>=0 && right<=n-1){
//                     if(s[left] == s[right]){
//                     left--;
//                     right++;
//                     count += 2;
//                     }
//                 }
//             }else{
//                  while(left>=0 && right<=n-1){
//                     if(s[left] == s[right]){
//                     left--;
//                     right++;
//                     count += 2;
//                     }
//                 }
//                 count +=1;
//             }

//             quanti.push_back(count);
        
//         }
//         return *max_element(quanti.begin(), quanti.end());
//     }
// };

// return the string cannot deal with "aaaa"
// class Solution{
//     public:
//     string longestPalindrome(string s){
//         if(s.length() <= 1) return s;
//         unordered_map<string,int> strAndLen;
//         string answerSubSt;
//         int n = s.length();
//         for(int i=1; i<=n/2; i++){
//             int left = i-1;
//             int right =i+1;
//             int count = 0;
//             if(s[left] == s[i] && s[right] != s[i]){
//                 right = i;
//                 while(left>=0 && right<=n-1 && s[left] == s[right]){
//                     left--;
//                     right++;
//                     count += 2;
//                 }
//             }else if(s[right] == s[i] && s[left] != s[i]){
//                 left = i;
//                 while(left>=0 && right<=n-1 && s[left] == s[right]){
//                     left--;
//                     right++;
//                     count += 2; 
//                 }
//             }else{
//                  while(left>=0 && right<=n-1 && s[left] == s[right]){
//                     left--;
//                     right++;
//                     count += 2;
//                 }
//                 count +=1;
//             }

//             strAndLen[s.substr(left + 1, right -left-1)] = count;
        
//         }

//         int maxLen = 0;
//         for(auto pair: strAndLen){
//             if(pair.second > maxLen ){
//                 maxLen = pair.second;
//                 answerSubSt = pair.first;
//             }
//         }
//         return answerSubSt;
//     }
// };

//别人的中心扩展算法：新定义了一函数
// class Solution{
//     public:
//     pair<int,int> getIndex(string s, int left, int right){
//         int n = s.length();
//         while(left>=0 && right<n && s[left]==s[right]){
//             left--;
//             right++;
//         }
//         return {left + 1,right -1 };
        
//     }
    
//     string longestPalindrome(string s){
//         int n = s.length();
//         int start=0, end=0;
//         if(n<2) return s;
//         for(int i =0; i<n; i++){
//             auto [left1,right1] = getIndex(s,i,i);
//             auto [left2,right2] = getIndex(s,i,i + 1);

//             if (right1-left1 > end - start){
//                 start = left1;
//                 end = right1;
//             }

//             if(right2-left2 > end - start){
//                 start = left2;
//                 end = right2;
//             }
//         }

//         return s.substr(start, end - start + 1);

//     }
// };

//动态规划
class Solution{
    public:
    string longestPalindrome(string s){
        int n = s.length();
        if(n<2) return s;

        vector<vector<bool>> dp(n, vector<bool>(n));
        int maxLen = 1, start = 0;
        for(int i = 0; i<n; i++){
            dp[i][i] = true;
        }

        for(int L = 2; L<=n; L++){
            for(int i = 0; i<n; i++){
                int j = i + L -1;
                if(j >= n) break;
                if(s[i] == s[j]){
                    if(j-i<3){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if(j - i + 1 > maxLen && dp[i][j]){
                    maxLen = j - i + 1;
                    start = i;
                }

            }
        }
        return s.substr(start,maxLen);
    }
};


int main(){
    string s = "babbad";
    Solution sol;
    string longti = sol.longestPalindrome(s);
    cout<<"answer is: "<< longti <<endl;
    return 0;
}