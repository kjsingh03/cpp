#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
  public:
  
    void traverse(vector<vector<int>>& adj, vector<vector<int>>& r, vector<int>& vis, vector<int>& temp, int node){
        vis[node]=1;
        temp.push_back(node);
        
        for(int i=0;i<adj.size();i++){
            if(adj[node][i]==1 && !vis[i]){
                traverse(adj, r, vis, temp, i);
            }
        }
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& e) {
        
        vector<vector<int>> adj(V,vector<int>(V,0));
        
        int n = e.size();
        
        for(int i=0;i<n;i++){
            int u=e[i][0], v=e[i][1];
            adj[u][v]=1;
            adj[v][u]=1;
        }
        
        vector<vector<int>> r;
        vector<int> temp;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                traverse(adj,r,vis,temp,i);
                r.push_back(temp);
                temp.clear();
            }
        }
        
        return r;
        
    }
};