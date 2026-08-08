#include<stdlib.h>
#include<iostream>
using namespace std;

int main(){

    int N, M;

    cin>>N>>M;

    // cout<<N<<M<<endl;

    vector<vector<int>> adj(N,vector<int>(N,0));

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }

    cout<<"  ";

    for(int i=0;i<N;i++){
        cout<<i<<" ";
    }

    cout<<endl;

    for(int i=0;i<N;i++){
        cout<<i<<" ";
        for(int j=0;j<N;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}