#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& v) {
        
        int n = v.size(), i = 0, j = 0, maxi = 0;
        map<int,int> mpp;

        while(i<n){
            mpp[v[i]]++;
            while(mpp.size()>2 && j<=i){
                if(mpp[v[j++]]--==1){
                    mpp.erase(v[j-1]);
                }
            }
            maxi=max(maxi,i++-j+1);
        }

        return maxi;
    }
};