#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j]=INT_MAX;
            }
        }

        vector<int> dy = {1,-1,0,0};
        vector<int> dx = {0,0,1,-1};

        while(!q.empty()){
            auto [y,x] = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int ny = y + dy[i], nx = x + dx[i];
                if(ny<0 || ny>=n || nx<0 || nx>=m || mat[ny][nx]!=INT_MAX)
                    continue;
                mat[ny][nx]=min(mat[ny][nx],mat[y][x]+1);
                q.push({ny,nx});
            }
        }

        return mat;
    }
};