#include "00graph_utils.h"

int main() {

    Graph g(10, 40);

    g.generateRandom();

    g.printMatrix();
    g.printList();

    return 0;
}