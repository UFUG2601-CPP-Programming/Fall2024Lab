#include "linked_list.h"

void LinkedList::insertFront(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAfterKey(int key, int data) {
    Node* current = head;
    while (current != nullptr && current->data != key) {
        current = current->next;
    }
    if (current == nullptr) {
        std::cout << "Key not found" << std::endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}