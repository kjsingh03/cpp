#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& v) {
        int n = v.size();

        int l=0,h=n-1,mid=-1,mini=INT_MAX;

        while(l<=h){
            mid=l+(h-l)/2;
            if(v[l]<=v[mid]){
                mini=min(mini,v[l]);
                l=mid+1;
            } else{
                mini=min(mini,v[mid]);
                h=mid-1;
            }
        }

        return mini;
    }
};