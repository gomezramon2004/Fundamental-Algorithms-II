#include "binarySearch.hpp"
#include <algorithm>

// Search for matching elements in the list to the left of 'node'.
void searchByLeft(const std::string& input, Node* node, LinkedList& output) {
    Node* current = node->prev;

    while (current && current->info.ubi.substr(0, 3) == input) {
        output.insertNode(current->info);
        current = current->prev;
    }
}

// Search for matching elements in the list to the right of 'node'
void searchByRight(const std::string& input, Node* node, LinkedList& output) {
    Node* current = node->next;

    while (current && current->info.ubi.substr(0, 3) == input) {
        output.insertNode(current->info);
        current = current->next;
    }
}

// Perform binary search on the given 'list' for elements with a prefix 'input'
LinkedList binarySearch(const LinkedList& list, const std::string& input) {
    LinkedList output;
    Node* left = list.head;
    Node* right = list.tail;

    while (left && right && left != right->next) {
        Node* mid = list.getMid(left, right);
        std::string key = mid->info.ubi.substr(0, 3);

        if (key == input) {
            // If a match is found at 'mid', search to the left and right of 'mid'
            searchByLeft(input, mid, output);
            output.insertNode(mid->info);
            searchByRight(input, mid, output);
            return output;
        }

         // Adjust the 'left' or 'right' pointers based on the comparison with 'key'
        key < input ? (left = mid->next) : (right = mid->prev);
    }

    return output;
}
