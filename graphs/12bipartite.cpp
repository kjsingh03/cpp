#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();

        vector<int> vis(n,-1);
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(vis[i]!=-1) continue;
            q.push({i,1});
            vis[i]=1;
            while(!q.empty()){
                auto [top,color] = q.front(); q.pop();
                for(int j:adj[top]){
                    if(vis[j]==-1){
                        vis[j]=!color;
                        q.push({j,!color});
                    } else if(vis[j]==color){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};