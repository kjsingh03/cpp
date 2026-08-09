#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int color) {
        if(mat[sr][sc]==color) return mat;

        int n = mat.size(), m = mat[0].size(), og = mat[sr][sc];

        queue<pair<int,int>> q;
        q.push({sr,sc});
        mat[sr][sc]=color;

        vector<int> dy = {1,-1,0,0};
        vector<int> dx = {0,0,1,-1};

        while(!q.empty()){
            auto [y,x] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int ny = y + dy[i], nx = x + dx[i];
                if(ny<0 || ny>=n || nx<0 || nx>=m)
                    continue;
                if(mat[ny][nx]==og){
                    q.push({ny,nx});
                    mat[ny][nx]=color;
                }
            }
        }

        return mat;
    }
};