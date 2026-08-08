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