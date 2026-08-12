#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& v, int b, int f) {
        int n = v.size(), maxi = *max_element(v.begin(),v.end()), mini=*min_element(v.begin(),v.end()), c = 0, d = 0;

        if((long long)b*f>n) return -1;

        int l=mini,h=maxi,mid=-1;

        while(l<=h){
            mid=l+(h-l)/2;
            c = 0;
            d = 0;
            for(int j=0;j<n;j++){
                if(v[j]<=mid){
                    c++;
                } else{
                    d+=c/f;
                    c=0;
                }
            }
            if(c!=0)
                d+=c/f;
            if(d<b)
                l=mid+1;
            else
                h=mid-1;
        }

        return l;
    }
};