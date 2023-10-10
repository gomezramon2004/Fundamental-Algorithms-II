#include "linkedList.hpp"

Node::Node(Info data) : data(data), next(nullptr) {}

Info Node::getData() {
    return data;
}

Node* Node::getNext() {
    return next;
}

void Node::setData(Info data) {
    this->data = data;
}

void Node::setNext(Node* next) {
    this->next = next;
}

LinkedList::LinkedList() : size(0), head(nullptr) {}

int LinkedList::getSize() {
    return size;
}

Node* LinkedList::getHead() {
    return head;
}

void LinkedList::create(Info data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->getNext()) {
            curr = curr->getNext();
        }
        curr->setNext(newNode);
    }
    size++;
}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}