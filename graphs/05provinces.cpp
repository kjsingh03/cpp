#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size(), c = 0;

        queue<int> q;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            q.push(i);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                if(vis[top]) continue;
                vis[top]=1;
                for(int j=0;j<n;j++){
                    if(mat[top][j] && top!=j)
                        q.push(j);
                }
            }
            c++;
        }


        return c;
    }
};