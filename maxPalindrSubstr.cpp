// Online C++ compiler to run C++ program online
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>
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

// return the string
class Solution{
    public:
    string longestPalindrome(string s){
        unordered_map<string,int> strAndLen;
        string answerSubSt;
        int n = s.length();
        for(int i=1; i<=n/2; i++){
            int left = i-1;
            int right =i+1;
            int count = 0;
            if(s[left] == s[i] && s[right] != s[i]){
                right = i;
                while(left>=0 && right<=n-1 && s[left] == s[right]){
                    left--;
                    right++;
                    count += 2;
                }
            }else if(s[right] == s[i] && s[left] != s[i]){
                left = i;
                while(left>=0 && right<=n-1 && s[left] == s[right]){
                    left--;
                    right++;
                    count += 2; 
                }
            }else{
                 while(left>=0 && right<=n-1 && s[left] == s[right]){
                    left--;
                    right++;
                    count += 2;
                }
                count +=1;
            }

            strAndLen[s.substr(left + 1, right -left-1)] = count;
        
        }

        int maxLen = 0;
        for(auto pair: strAndLen){
            if(pair.second > maxLen ){
                maxLen = pair.second;
                answerSubSt = pair.first;
            }
        }
        return answerSubSt;
    }
};


int main(){
    string s = "babbad";
    Solution sol;
    string longti = sol.longestPalindrome(s);
    cout<<"answer is: "<< longti <<endl;
    return 0;
}