#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), c = 0;

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1))
                    q.push({i,j});
                else if(mat[i][j])
                    mat[i][j]=-1;
            }
        }

        vector<int> dy = {1,-1,0,0};
        vector<int> dx = {0,0,1,-1};

        while(!q.empty()){
            auto [y,x] = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int ny = y + dy[i], nx = x + dx[i];
                if(ny<0 || ny >= n || nx <0 || nx >=m || mat[ny][nx]!=-1)
                    continue;
                mat[ny][nx]=1;
                q.push({ny,nx});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==-1)
                    c++;
            }
        }

        return c;
    }
};