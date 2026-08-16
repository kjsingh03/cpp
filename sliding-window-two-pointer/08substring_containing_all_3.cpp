#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), r = 0, mini = INT_MAX;

        int last[3] = {-1, -1, -1};

        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
            mini = min({last[0], last[1], last[2]});
            if (mini != -1) {
                r += mini + 1;
            }
        }

        return r;
    }
};