#include "mergeSort.hpp"
#include <iostream>

bool compareInfo(const Info& info1, const Info& info2, const bool& option) {
    if (!option) {
        if (info1.ubi == info2.ubi) {
            return info1.timeValue < info2.timeValue;
        }
        return info1.ubi < info2.ubi;
    } 
    return info1.monthValue < info2.monthValue;
}

LinkedList mergeLists(LinkedList& left, LinkedList& right, const bool& option) {
    LinkedList mergedList;
    Node* leftPtr = left.head;
    Node* rightPtr = right.head;

    while (leftPtr != nullptr && rightPtr != nullptr) {
        if (compareInfo(leftPtr->info, rightPtr->info, option)) {
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

LinkedList mergeSort(LinkedList& list, const bool& option) {
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

    leftHalf = mergeSort(leftHalf, option);
    rightHalf = mergeSort(rightHalf, option);

    // Merge the sorted halves and return the result.
    return mergeLists(leftHalf, rightHalf, option);
}

