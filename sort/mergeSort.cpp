#include "mergeSort.hpp"
#include <iostream>

// Function to compare two Info objects based on 'ubi' and 'timeValue' or 'onlyTime'.
bool compareInfo(const Info& info1, const Info& info2, const bool& onlyTime) {
    if (info1.ubi == info2.ubi || onlyTime) {
        return info1.timeValue < info2.timeValue;
    }
    return info1.ubi < info2.ubi;
}

// Function to merge two linked lists ('left' and 'right') into a new sorted list based on 'onlyTime'.
LinkedList mergeLists(LinkedList& left, LinkedList& right, const bool& onlyTime) {
    LinkedList mergedList;
    Node* leftPtr = left.head;
    Node* rightPtr = right.head;

    while (leftPtr && rightPtr) {
        if (compareInfo(leftPtr->info, rightPtr->info, onlyTime)) {
            mergedList.insertNode(leftPtr->info);
            leftPtr = leftPtr->next;
        } else {
            mergedList.insertNode(rightPtr->info);
            rightPtr = rightPtr->next;
        }
    }

    while (leftPtr) {
        mergedList.insertNode(leftPtr->info);
        leftPtr = leftPtr->next;
    }

    while (rightPtr) {
        mergedList.insertNode(rightPtr->info);
        rightPtr = rightPtr->next;
    }

    return mergedList;
}

// Function to perform merge sort on a linked list based on 'onlyTime'.
LinkedList mergeSort(LinkedList& list, const bool& onlyTime) {
    if (!list.head || !list.head->next) {
        return list;  // Base case: List is empty or has one node; it's already sorted.
    }

    LinkedList leftHalf, rightHalf;
    Node* slow = list.head;
    Node* fast = list.head->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    leftHalf.head = list.head;
    leftHalf.tail = slow;
    rightHalf.head = slow->next;
    rightHalf.tail = list.tail;
    slow->next = nullptr;

    leftHalf = mergeSort(leftHalf, onlyTime);
    rightHalf = mergeSort(rightHalf, onlyTime);

    // Merge the sorted halves and return the result.
    return mergeLists(leftHalf, rightHalf, onlyTime);
}
