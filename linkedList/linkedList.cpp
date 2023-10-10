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

LinkedList::LinkedList() : size(0), head(nullptr), tail(nullptr) {}

int LinkedList::getSize() {
    return size;
}

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::getTail() {
    return tail;
}

void LinkedList::setHead(Node* head) {
    this->head = head;
}

void LinkedList::setTail(Node* tail) {
    this->tail = tail;
}

void LinkedList::insertNode(Info data) {
    Node* newNode = new Node(data);
    newNode->setData(data);
    newNode->setNext(nullptr);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
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
