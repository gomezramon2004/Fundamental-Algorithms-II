#include "mergeSort.hpp"
#include <iostream>

bool compareInfo(const Info& info1, const Info& info2) {
    if (info1.ubi == info2.ubi) {
        return info1.timeValue < info2.timeValue;
    }
    return info1.ubi < info2.ubi;
}

void mergeLists(LinkedList& left, LinkedList& right) {
    LinkedList mergedList;
    Node* leftPtr = left.getHead();
    Node* rightPtr = right.getHead();

    while (leftPtr && rightPtr) {
        if (compareInfo(leftPtr->getData(), rightPtr->getData())) {
            mergedList.insertNode(leftPtr->getData());
            leftPtr = leftPtr->getNext();
        } else {
            mergedList.insertNode(rightPtr->getData());
            rightPtr = rightPtr->getNext();
        }
    }

    while (leftPtr) {
        mergedList.insertNode(leftPtr->getData());
        leftPtr = leftPtr->getNext();
    }

    while (rightPtr) {
        mergedList.insertNode(rightPtr->getData());
        rightPtr = rightPtr->getNext()  ;
    }
}

void mergeSort(LinkedList& list) {
    if (list.getHead() || list.getHead()->getNext()) {         // Base case: List is empty or has one node; it's already sorted.
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

        leftHalf.setHead(list.getHead());
        leftHalf.setTail(slow);
        rightHalf.setHead(slow->getNext());
        rightHalf.setTail(list.getTail());
        slow->setNext(nullptr);

        mergeSort(leftHalf);
        mergeSort(rightHalf);

        // Merge the sorted halves and return the result.
        mergeLists(leftHalf, rightHalf);
    }
}