#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& v, int k) {
        int n = v.size();

        int l = 1, h = *max_element(v.begin(),v.end()), mid = -1;
        long long c= 0LL;

        while(l<=h){
            mid = l+(h-l)/2;
            c=0;
            for(int i=0;i<n;i++){
                c+=((1LL*v[i]+mid-1)/mid);
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