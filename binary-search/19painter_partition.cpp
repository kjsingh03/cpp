#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
using namespace std;

class Solution {
  public:
    int minTime(vector<int>& v, int k) {
        
        int n = v.size(), sum = accumulate(v.begin(),v.end(),0), maxi=*max_element(v.begin(),v.end());

        if(k==1) return sum;
        if(k>=n) return maxi;
                
        int l = maxi, h = sum, mid = -1, c = 0, s = 0;
        
        while(l<=h){
            mid=l+(h-l)/2;
            s=0; c=1;
            for(int i=0;i<n;i++){
                s+=v[i];
                if(s>mid){
                    c++;
                    s=v[i];
                }
            }
            if(c>k){
                l=mid+1;
            } else{
                h=mid-1;
            }
        }
                
        return l;
    }
};