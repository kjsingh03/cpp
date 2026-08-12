#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& v, int k) {
        int n = v.size(), maxi = *max_element(v.begin(),v.end());

        long long c = 0;

        if(k==n) return maxi;
        
        int l=1,h=maxi,mid=-1;

        while(l<=h){
            mid=l+(h-l)/2;
            c=0;
            for(int i=0;i<n;i++){
                c+=(((long long)v[i]+mid-1)/mid);
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