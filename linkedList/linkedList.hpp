#pragma once
#include <string>

struct Info {
    time_t timeValue; // Value that counts in seconds from 01/01/1970 to the corresponding date
    struct tm dateTime; // Struct that holds the data of our date
    char enterPoint;
    std::string ubi;
};

class Node {
    public: 
        Info info;
        Node* next;
        Node* prev;
};

class LinkedList {
    public:
        Node* head;
        Node* tail;
        int size;

        LinkedList();
        void insertNode(Info info);
        LinkedList divideList(char puerto_com);
        Node* getMid(Node* left, Node* right) const;
};

