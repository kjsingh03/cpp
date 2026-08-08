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