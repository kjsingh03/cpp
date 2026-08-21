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

// DP

class Solution {
public:
    string minWindow(string& s, string& t) {
        int n = s.size(), m = t.size();
        vector<int> dp(m, -1);

        int mini = INT_MAX, start = -1;

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    if (j == 0)
                        dp[j] = i;
                    else if (dp[j - 1] != -1)
                        dp[j] = dp[j - 1];
                }
            }

            if (dp[m - 1] != -1) {
                int len = i - dp[m - 1] + 1;

                if (len < mini) {
                    mini = len;
                    start = dp[m - 1];
                }
            }
        }

        return start == -1 ? "" : s.substr(start, mini);
    }
};