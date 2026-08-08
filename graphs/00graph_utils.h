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