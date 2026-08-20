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

// Insert at beginning
Node* insertAtBeginning(Node* head, int x) {
    Node* newNode = new Node(x);
    newNode->next = head;
    return newNode;
}

// Insert at end
Node* insertAtEnd(Node* head, int x) {
    Node* newNode = new Node(x);

    // If list is empty
    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Delete from beginning
Node* deleteFromBeginning(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    head = head->next;

    delete temp;

    return head;
}

// Delete from end
Node* deleteFromEnd(Node* head) {
    // Empty list
    if (head == nullptr) {
        return nullptr;
    }

    // Only one node
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    // Insertion
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    cout << "After insertion:\n";
    printList(head);

    // Deletion from beginning
    head = deleteFromBeginning(head);

    cout << "After deleting from beginning:\n";
    printList(head);

    // Deletion from end
    head = deleteFromEnd(head);

    cout << "After deleting from end:\n";
    printList(head);

    return 0;
}