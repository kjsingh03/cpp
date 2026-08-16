#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int calc(vector<int>& v, int k){
        int n = v.size(), c = 0, s = 0, i = 0, j = 0;

        while(i<n){
            s+=v[i];
            while(s>k && j<=i){
                s-=v[j++];
            }
            c+=(i++-j+1);
        }

        return c;
    }

    int numSubarraysWithSum(vector<int>& v, int k) {
        return calc(v,k)-calc(v,k-1);
    }
};