#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();

        int l=0,h=n-1,mid=-1;

        while(l<=h){
            mid=l+(h-l)/2;
            if(mid&1){
                if(mid>0 && v[mid]==v[mid-1])
                    l=mid+1;
                else
                    h=mid-1;
            } else{
                if(mid>0 && v[mid]==v[mid-1])
                    h=mid-1;
                else
                    l=mid+1;
            }
        }

        return v[h];
    }
};