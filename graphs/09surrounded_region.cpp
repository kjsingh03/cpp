#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& mat) {
        int n=mat.size(), m=mat[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1)){
                    q.push({i,j});  
                } else if(mat[i][j]=='O'){
                    mat[i][j]='A';
                }                          
            }
        } 

        vector<int> dy = {1,-1,0,0};
        vector<int> dx = {0,0,1,-1};

        while(!q.empty()){
            auto [y,x] = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int ny=y+dy[i], nx=x+dx[i];
                if(ny<0 || ny>=n || nx<0 || nx>=m || mat[ny][nx]!='A')
                    continue;
                mat[ny][nx]='O';
                q.push({ny,nx});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='A')
                    mat[i][j]='X';
            }
        }
    }
};