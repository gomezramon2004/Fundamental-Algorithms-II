#include "linkedList.hpp"
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <iostream>

// Constructor
LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// Insert a new node
void LinkedList::insertNode(Info info) {
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

LinkedList LinkedList::divideList(char puerto_com){
    LinkedList list;
    Node* temp = head;

    while (temp) {
        if (temp->info.enterPoint == puerto_com) {
            list.insertNode(temp->info);
        }
        temp = temp->next;
    }

    return list;
}

Node* LinkedList::getMid(Node* left, Node* right) const {
    if (!left || !right) {
        return nullptr;
    }

    Node* slow = left;
    Node* fast = left;

    while (fast != right && fast->next != right) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// strptime(dateTime,"%d/%m/%Y %H:%M", &timeStruct); We can't use strptime because Windows isn't POSIX Compliant
// https://stackoverflow.com/questions/321849/strptime-equivalent-on-windows
// https://www.quora.com/Why-doesnt-Microsoft-make-Windows-POSIX-compliant 