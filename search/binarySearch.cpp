#include "binarySearch.hpp"
#include <algorithm>

void searchByLeft(const std::string& input, Node* node, LinkedList& output) {
    Node* current = node->prev;

    while (current && current->info.ubi.substr(0, 3) == input) {
        output.insertNode(current->info);
        current = current->prev;
    }
}

void searchByRight(const std::string& input, Node* node, LinkedList& output) {
    Node* current = node->next;

    while (current && current->info.ubi.substr(0, 3) == input) {
        output.insertNode(current->info);
        current = current->next;
    }
}

LinkedList binarySearch(const LinkedList& list, const std::string& input) {
    LinkedList output;
    Node* left = list.head;
    Node* right = list.tail;

    while (left && right && left != right->next) {
        Node* mid = list.getMid(left, right);
        std::string key = mid->info.ubi.substr(0, 3);

        if (key == input) {
            searchByLeft(input, mid, output);
            output.insertNode(mid->info);
            searchByRight(input, mid, output);
            return output;
        }

        key < input ? (left = mid->next) : (right = mid->prev);
    }

    return output;
}