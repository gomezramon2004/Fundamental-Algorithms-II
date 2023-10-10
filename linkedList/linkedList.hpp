#pragma once
#include <stdexcept>
#include <string>

struct Info {
    time_t timeValue; // Value that counts in seconds from 01/01/1970 to the corresponding date
    struct tm dateTime; // Struct that holds the data of our date
    char enterPoint;
    std::string ubi;
};

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
    Node* tail;

public:
    LinkedList();
    int getSize();
    Node* getHead();
    Node* getTail();
    void setHead(Node* head);
    void setTail(Node* tail);
    void insertNode(Info data);
    ~LinkedList();
};



