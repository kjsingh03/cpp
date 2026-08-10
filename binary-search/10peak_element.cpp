#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n = v.size(), maxi = 0;

        if(n==1 || v[0] > v[1]) return 0;
        if(v[n-1] > v[n-2]) return n-1;

        int l = 1, h = n - 2, mid = -1;

        while(l<=h){
            mid=l+(h-l)/2;
            if(v[mid-1]<v[mid] && v[mid]>v[mid+1])
                return mid;
            if(v[mid]>v[mid-1]) l=mid+1;
            else h=mid-1;
        }

        return -1;
    }
};