#include "mergeSort.hpp"
#include <iostream>

bool compareInfo(const Info& info1, const Info& info2) {
    if (info1.ubi == info2.ubi) {
        return info1.timeValue < info2.timeValue;
    }
    return info1.ubi < info2.ubi;
}

LinkedList mergeLists(LinkedList& left, LinkedList& right) {
    LinkedList mergedList;
    Node* leftPtr = left.head;
    Node* rightPtr = right.head;

    while (leftPtr && rightPtr) {
        if (compareInfo(leftPtr->info, rightPtr->info, option)) {
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

LinkedList mergeSort(LinkedList& list) {
    if (!list.getHead() || !list.getHead()->getNext()) {         // Base case: List is empty or has one node; it's already sorted.
        return list;
    }

    LinkedList leftHalf, rightHalf;
    Node* slow = list.getHead();
    Node* fast = list.getHead()->getNext();

    while (fast) {
        fast = fast->getNext();
        if (fast) {
            slow = slow->getNext();
            fast = fast->getNext();
        }
    }

    leftHalf.getHead() = list.getHead();
    leftHalf.tail = slow;
    rightHalf.getHead() = slow->getNext();
    rightHalf.tail = list.tail;
    slow->getNext() = nullptr;

    leftHalf = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);

    // Merge the sorted halves and return the result.
    return mergeLists(leftHalf, rightHalf);
}