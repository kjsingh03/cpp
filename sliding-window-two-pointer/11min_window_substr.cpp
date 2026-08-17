#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size(), m = t.size(); 

        if(m>n) return "";

        map<char,int> mpp;

        for(char ch: t){
            mpp[ch]++;
        }

        int i = 0, j = 0, mini = INT_MAX, c = m, start = 0;

        while(i<n){
            char ch = s[i];
            if(mpp.count(ch)){
                if(mpp[ch]>0)
                    c--;
                mpp[ch]--;
            }

            while(c==0 && j<=i){
                if(mini>i-j+1){
                    mini=i-j+1;
                    start = j;
                }
                if(mpp.count(s[j])){
                    if(mpp[s[j]]++==0)
                        c++;
                }
                j++;
            }
            i++;
        }

        if(mini==INT_MAX) return "";
        return s.substr(start,mini);
    }
};