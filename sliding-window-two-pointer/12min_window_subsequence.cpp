#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string minWindow(string& s, string& t) {

        int n = s.size(), m = t.size(), mini = INT_MAX, start = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] != t[0]) continue;

            int j = i, k = 0;

            while (j < n && k < m) {
                if (s[j] == t[k])
                    k++;
                j++;
            }

            if (k != m) break;

            int end = j - 1;

            k = m - 1;
            j = end;

            while (j >= i) {
                if (s[j] == t[k]) {
                    k--;
                    if (k < 0) break;
                }
                j--;
            }

            int st = j;
            int len = end - st + 1;

            if (len < mini) {
                mini = len;
                start = st;
            }
        }

        return start == -1 ? "" : s.substr(start, mini);
    }
};