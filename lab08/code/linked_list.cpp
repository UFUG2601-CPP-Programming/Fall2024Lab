#include "linked_list.h"

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insertFront(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertBack(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
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