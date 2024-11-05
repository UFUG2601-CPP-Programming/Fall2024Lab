#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(): data(0), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    Node* getHead() { return head; }
    void insertFront(int data);
    void insertAfterKey(int key, int data);
    void deleteNode(int key);
    bool searchKey(int key);
    void print();
};