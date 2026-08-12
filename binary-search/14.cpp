#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& v, int k) {
        
        int n = v.size();

        long long s = accumulate(v.begin(),v.end(),0LL), c = 0LL, sum = 0LL;
        if(k==1) return s;
        if(k==s) return 1;

        int maxi = *max_element(v.begin(),v.end());
        if(k==n) return maxi;
        
        int l = maxi, h = s, mid = -1;

        while(l<=h){
            mid = l + (h-l)/2;
            c=1LL;
            sum=0LL;
            for(int i=0;i<n;i++){
                sum+=v[i];
                if(sum>mid){
                    c++;
                    sum=v[i];
                }
            }
            if(c<=k){
                h=mid-1;
            } else{
                l=mid+1;
            }
        }

        return l;
    }
};