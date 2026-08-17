#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        
        int n = s.size(), i = 0, j = 0, maxi = 0;
        
        map<char,int> mpp;
        
        while(i<n){
            char ch = s[i];
            mpp[ch]++;
            while(mpp.size()>k && j<=i){
                if(mpp[s[j++]]--==1)
                    mpp.erase(s[j-1]);
            }
            if(mpp.size()==k)
                maxi=max(maxi,i-j+1);
            i++;
        }
        
        return maxi==0?-1:maxi;
    }
};