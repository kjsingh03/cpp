#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
using namespace std;

class Solution {
  public:
    int aggressiveCows(vector<int> &v, int k) {
        
        int n = v.size();
        
        int maxi=*max_element(v.begin(),v.end()), mini = *min_element(v.begin(),v.end());
        int diff = INT_MAX;
        
        sort(v.begin(),v.end());
        
        for(int i=1;i<n;i++){
            diff=min(diff,abs(v[i]-v[i-1]));
        }
        
        if(k==n) return diff;
        if(k<=2) return maxi-mini;
        
        int l = diff, h = (maxi-mini), mid = -1, last = 0, c = 0;
        
        while(l<=h){
            mid=l+(h-l)/2;
            last=0; c = 1;
            for(int i=1;i<n;i++){
                diff=v[i]-v[last];
                if(diff>=mid){
                    last=i;
                    c++;
                }
            }
            if(c>=k)
                l=mid+1;
            else
                h=mid-1;
        }
        
        return h;
    }
};