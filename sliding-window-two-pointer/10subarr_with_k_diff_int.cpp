#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int calc(vector<int>& v, int k){
        
        int n = v.size(), c = 0, i = 0, j = 0;

        map<int,int> mpp;

        while(i<n){
            mpp[v[i]]++;
            while(mpp.size()>k && j<=i){
                if(mpp[v[j++]]--==1)
                    mpp.erase(v[j-1]);
            }
            c+=(i++-j+1);
        }

        return c;
    }
    int subarraysWithKDistinct(vector<int>& v, int k) {
        return calc(v,k)-calc(v,k-1);
    }
};