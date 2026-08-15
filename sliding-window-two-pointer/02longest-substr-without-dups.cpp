#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // My Optimal
        
        int n = s.size(), maxi = 0, i = 0, j = 0;

        map<char,int> mpp;

        while(i<n){
            char ch = s[i];
            mpp[ch]++;
            while(mpp[ch]>=2 && j<i){
                mpp[s[j]]--;
                j++;
            }
            maxi=max(maxi,i++-j+1);
        }

        return maxi;


        // My Bruteforce 


        // int n = s.size(), c = 0, maxi = INT_MIN;

        // map<char,int> mpp;

        // for(int i=0;i<n;i++){
        //     c=0;
        //     for(int j=i;j<n;j++){
        //         char ch = s[j];
        //         if(!mpp.count(ch)){
        //             c++;
        //             mpp[ch]++;
        //         }
        //         else
        //             break;
        //     }
        //     maxi=max(maxi,c);
        //     mpp.clear();
        // }

        // return maxi;
    }
};