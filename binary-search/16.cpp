#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& v, int k) {

        // My Optimal Solution

        int n=v.size();

        int maxi=*max_element(v.begin(),v.end());
        int total=accumulate(v.begin(),v.end(),0);

        int sum=0,c=0,low=maxi,high=total;

        while(low<=high){
            int mid=low+(high-low)/2;

            sum=0;c=1;

            for(int i=0;i<n;i++){
                sum+=v[i];
                if(sum>mid){
                    c++;
                    sum=v[i];
                }
            }

            if(c>k) low=mid+1;
            else high=mid-1;
        }

        return low;
    }
};