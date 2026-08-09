#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), c = 0, t = 0;

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)
                    c++;
                else if(mat[i][j]==2)
                    q.push({i,j});
            }
        }

        if(c==0) return 0;

        vector<int> dy = {1,-1,0,0}, dx = {0,0,1,-1};

        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto [y,x] = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int ny = y + dy[j], nx = x + dx[j];
                    if(ny<0 || ny>=n || nx<0 || nx>=m )
                        continue;
                    if(mat[ny][nx]==1){
                        mat[ny][nx]=2;
                        q.push({ny,nx});
                        c--;
                    }
                }
            }
            t++;
            if(c==0)
                return t;
        }

        if(c==0)
            return t;

        return -1;
    }
};