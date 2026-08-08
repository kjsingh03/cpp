#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){

    int N,M;

    cin>>N>>M;

    vector<vector<int>> adj(N);

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0;i<N;i++){
        cout<<i<<"->";
        for(int j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}