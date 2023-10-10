#pragma once
#include <stdexcept>
#include "../parse/parse.hpp"

class Node {
private:
    Info data;
    Node* next;

public:
    Node(Info data);
    Info getData();
    Node* getNext();
    void setData(Info data);
    void setNext(Node* next);
};

class LinkedList {
private:
    int size;
    Node* head;

public:
    LinkedList();
    int getSize();
    Node* getHead();
    void create(Info data);
    ~LinkedList();
};
