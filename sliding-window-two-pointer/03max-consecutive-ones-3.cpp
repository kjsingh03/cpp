#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size(), maxi = 0, i = 0, j = 0;

        while(i<n){
            if(v[i]!=1)
                k--;
            while(k<0 && j<=i){
                if(v[j++]==0)
                    k++;
            }
            maxi=max(maxi,i++-j+1);
        }

        return maxi;
    }
};