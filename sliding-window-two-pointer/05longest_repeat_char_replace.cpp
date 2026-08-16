#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), i = 0, j = 0, maxi = 0, maxE = 0;
        char a = s[0];

        map<char,int> mpp;

        while(i<n){
            char ch = s[i];
            mpp[ch]++;
            maxE=max(maxE,mpp[ch]);
            while((i-j+1-maxE)>k && j<=i){
                mpp[s[j++]]--;
            }
            maxi=max(maxi,i++-j+1);
        }

        return maxi;
    }
};