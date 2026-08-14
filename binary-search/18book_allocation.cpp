#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
using namespace std;

class Solution {
  public:
    int findPages(vector<int> &v, int k) {
       
        long long sum = accumulate(v.begin(), v.end(), 0LL);
        long long maxi = *max_element(v.begin(), v.end());
        
        int n = v.size();
        
        if (k > n)
            return -1;
        
        if (k == 1)
            return sum;
        
        long long l = maxi;
        long long h = sum;
        
        while (l <= h) {
            long long mid = l + (h - l) / 2;
        
            int students = 1;
            long long pages = 0;
        
            for (int i = 0; i < n; i++) {
                if (pages + v[i] > mid) {
                    students++;
                    pages = v[i];
                } else {
                    pages += v[i];
                }
            }
        
            if (students <= k)
                h = mid - 1;
            else
                l = mid + 1;
        }
        
        return l;
    }
};