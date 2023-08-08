#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

static Node* head = nullptr;

static void reverseLinkedList() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* p1 = head;
    Node* p2 = head->next;
    Node* p3 = nullptr;

    while (p2 != nullptr) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    head->next = nullptr;
    head = p1;
}

int main() {
    // Initialize the linked list
    head = new Node(3);
    head->next = new Node(5);
    Node* temp = head->next;
    temp->next = new Node(1);
    temp = temp->next;
    temp->next = new Node(4);
    temp = temp->next;
    temp->next = new Node(9);

    // Print the linked list before reversing
    temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }

    // Reverse the linked list
    reverseLinkedList();

    // Print the linked list after reversing
    temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }

    return 0;
}
