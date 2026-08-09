#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& mat) {
        
        int n = mat.size(), m = mat[0].size(), c=0;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));


        vector<int> dy= {1,-1,0,0};
        vector<int> dx = {0,0,1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || mat[i][j]=='0') continue;
                q.push({i,j});
                while(!q.empty()){
                    auto [y,x] = q.front(); q.pop();
                    if(vis[y][x]) continue;
                    vis[y][x]=1;
                    for(int i=0;i<4;i++){
                        int ny = y + dy[i], nx = x + dx[i];
                        if(ny<0 || ny>=n || nx<0 || nx>=m || mat[ny][nx]=='0')
                            continue;
                        q.push({ny,nx});
                    }
                }
                c++;
            }
        }
        
        return c;
    }
};