#include "mergeSort.hpp"
#include <iostream>

bool compareInfo(const Info& info1, const Info& info2, const bool& onlyTime) {
    if (info1.ubi == info2.ubi || onlyTime) {
        return info1.timeValue < info2.timeValue;
    }
    return info1.ubi < info2.ubi;
}

LinkedList mergeLists(LinkedList& left, LinkedList& right, const bool& onlyTime) {
    LinkedList mergedList;
    Node* leftPtr = left.head;
    Node* rightPtr = right.head;

    while (leftPtr != nullptr && rightPtr != nullptr) {
        if (compareInfo(leftPtr->info, rightPtr->info, onlyTime)) {
            mergedList.insertNode(leftPtr->info);
            leftPtr = leftPtr->next;
        } else {
            mergedList.insertNode(rightPtr->info);
            rightPtr = rightPtr->next;
        }
    }

    while (leftPtr != nullptr) {
        mergedList.insertNode(leftPtr->info);
        leftPtr = leftPtr->next;
    }

    while (rightPtr != nullptr) {
        mergedList.insertNode(rightPtr->info);
        rightPtr = rightPtr->next;
    }

    return mergedList;
}

LinkedList mergeSort(LinkedList& list, const bool& onlyTime) {
    if (list.head == nullptr || list.head->next == nullptr) {
        // Base case: List is empty or has one node; it's already sorted.
        return list;
    }

    LinkedList leftHalf, rightHalf;
    Node* slow = list.head;
    Node* fast = list.head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
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

