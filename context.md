

## arrays/test.cpp

```cpp
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){

    int n;

    cin>>n;

    cout<<"Hello "<<n<<endl;

    return 0;
}
```


## graphs/00graph_utils.cpp

```cpp
#include "00graph_utils.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Graph::Graph(int n, int m) {

    N = n;
    M = m;

    mat = vector<vector<int>>(N, vector<int>(N, 0));
    adj = vector<vector<int>>(N);
}

void Graph::generateRandom() {

    srand(time(0));

    int count = 0;

    while(count < M) {

        int a = rand() % N;
        int b = rand() % N;

        if(a == b)
            continue;

        if(mat[a][b] == 1)
            continue;

        mat[a][b] = 1;
        mat[b][a] = 1;

        adj[a].push_back(b);
        adj[b].push_back(a);

        count++;
    }
}

void Graph::printMatrix() {

    cout << "============== Adjacency Matrix ==============" << endl;

    cout << "  ";

    for(int i = 0; i < N; i++)
        cout << i << " ";

    cout << endl;

    for(int i = 0; i < N; i++) {
        cout << i << " ";
        for(int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void Graph::printList() {

    cout << "============== Adjacency List ==============" << endl;

    for(int i = 0; i < N; i++) {
        cout << i << " -> ";
        for(int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}
```


## graphs/00graph_utils.h

```h
#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include <vector>
using namespace std;

class Graph {
public:

    int N;
    int M;

    vector<vector<int>> mat, adj;

    Graph(int n, int m);

    void generateRandom();

    void printMatrix();

    void printList();
};

#endif
```


## graphs/00seed_data.cpp

```cpp
#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

int main() {

    int N, M;

    cin >> N >> M;

    srand(time(0));

    int count = 0;

    vector<vector<int>> mat(N, vector<int>(N, 0));
    vector<vector<int>> adj(N);

    while(count < M) {

        int a = rand() % N;
        int b = rand() % N;

        if(a == b)                  // Self-loop
            continue;

        if(mat[a][b] == 1)          // Duplicate edge
            continue;

        mat[a][b] = 1;
        mat[b][a] = 1;

        adj[a].push_back(b);
        adj[b].push_back(a);

        count++;
    }

    // for(int i = 0; i < M; i++) {
    //     int a, b;
    //     cin >> a >> b;

    //     // Adjacency Matrix
    //     mat[a][b] = 1;
    //     mat[b][a] = 1;

    //     // Adjacency List
    //     adj[a].push_back(b);
    //     adj[b].push_back(a);
    // }

    cout << "============== Adjacency Matrix ==============" << endl;

    cout << "  ";

    for(int i = 0; i < N; i++) {
        cout << i << " ";
    }

    cout << endl;

    for(int i = 0; i < N; i++) {
        cout << i << " ";
        for(int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "============== Adjacency List ==============" << endl;

    for(int i = 0; i < N; i++) {
        cout << i << " -> ";
        for(int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    

    return 0;
}
```


## graphs/01adj_matrix.cpp

```cpp
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
```


## graphs/02adj_list.cpp

```cpp
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
```


## graphs/03connected_comp.tle.cpp

```cpp
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
```


## graphs/04bfs.cpp

```cpp
#include "00graph_utils.h"

int main() {

    Graph g(10, 40);

    g.generateRandom();

    g.printMatrix();
    g.printList();

    return 0;
}
```


## graphs/Solution.cpp

```cpp

```


## test.c

```c
#include<stdio.h>

int main(){

    int n;

    scanf("%d",&n);

    printf("Hello %d\n",n);

    return 0;
}
```
