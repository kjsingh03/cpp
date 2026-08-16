#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int calc(vector<int>& v, int k){
        int n = v.size(), c = 0, r = 0, i = 0, j = 0;

        while(i<n){
            if(v[i]&1)
                c++;
            while(c>k && j<=i){
                if(v[j++]&1)
                    c--;
            }
            r+=(i++-j+1);
        }

        return r;
    }
    int numberOfSubarrays(vector<int>& v, int k) {
        return calc(v,k)-calc(v,k-1);
    }
};