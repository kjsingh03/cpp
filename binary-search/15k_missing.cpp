#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        
        // Optimal

        int n= v.size();

        int l=0,h=n-1,c=0;

        while(l<=h){
            int mid = l + (h - l) / 2;

            c=v[mid]-mid-1;

            if(c<k)
                l = mid + 1;
            else
                h=mid-1;
        }

        return k+h+1;


        // Better


        // int n = v.size();
        
        // for(int i=0;i<n;i++){
        //     if(v[i]<=k)
        //         k++;
        //     else
        //         return k;
        // }

        // return k;


        // My Better
        

        // int n = v.size(), a = 0, j = 0;

        // for(int i=0;i<n;i++){
        //     while(k>0 && v[i]!=i+a+1){
        //         a++;
        //         k--;
        //     }
        // }

        // while(k>0){
        //     a++;
        //     k--;
        // }

        // return n+a;
        

        // My brute force


        // int n = v.size();

        // int maxi = *max_element(v.begin(),v.end());

        // vector<int> r(maxi+k+1,0);

        // for(int i=0;i<n;i++){
        //     r[v[i]]=1;
        // }

        // for(int i=1;i<r.size();i++){
        //     if(r[i]==0){
        //         k--;
        //         if(k==0) return i;
        //     }
        // }

        // return -1;
    }
};