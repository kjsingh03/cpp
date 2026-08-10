#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

class Solution {
public:
    int search(vector<int>& v, int k) {
        int n = v.size();

        int l = 0, h = n-1, mid = -1;

        while(l<=h){
            mid = l + (h - l)/2;
            if(v[mid]==k){
                return mid;
            }

            if (v[l] <= v[mid]) {
                if (v[l] <= k && k < v[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else {
                if (v[mid] < k && k <= v[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }

        return -1;
    }
};