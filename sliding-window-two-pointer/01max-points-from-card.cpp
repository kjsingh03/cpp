#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        
        int n = v.size(), s = 0, maxi = -1;

        if(n==1) return v[0];
        if(k==1) return v[0]>v[n-1]?v[0]:v[n-1];
        if(k==n) return accumulate(v.begin(),v.end(),0);

        maxi = s = accumulate(v.begin(),v.begin()+k,0);

        for (int i = 0; i < k; i++) {
            s-=v[k-1-i];
            s+=v[n-1-i];
            maxi = max(maxi, s);
        }

        return maxi;
    }
};