#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int x, Node* next = nullptr) {
        this->val = x;
        this->next = next;
    }
};

int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20, n1);

    cout << n2->val << " -> " << n2->next->val << endl;

    delete n2;
    delete n1;

    return 0;
}