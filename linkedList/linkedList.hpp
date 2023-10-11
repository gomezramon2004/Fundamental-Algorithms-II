#pragma once
#include <string>

// Structure to represent information about a ship's entry.
struct Info {
    time_t timeValue; // A value representing the date and time.
    struct tm dateTime; // A struct holding date and time data.
    char enterPoint; // Indicates the entry point (M for Mar Mediterráneo, R for Mar Rojo).
    std::string ubi; // Unique identifier for the ship.
};

// Class representing a node in a doubly linked list.
class Node {
    public:
        Info info; 
        Node* next; 
        Node* prev; 
};

// Class representing a doubly linked list of ship entries.
class LinkedList {
    public:
        Node* head; 
        Node* tail; 
        int size; 

        // Constructor to initialize an empty linked list.
        LinkedList();

        // Method to insert a new node with ship entry information.
        void insertNode(Info info);

        // Method to divide the list into two based on the entry point (puerto_com).
        LinkedList divideList(char puerto_com);

        // Method to find the middle node between two given nodes (left and right).
        Node* getMid(Node* left, Node* right) const;
};
