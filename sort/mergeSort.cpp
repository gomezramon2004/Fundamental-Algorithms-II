#include "mergeSort.hpp"
#include <iostream>

bool compareInfo(const Info& info1, const Info& info2) {
    if (info1.ubi == info2.ubi) {
        return info1.timeValue < info2.timeValue;
    }
    return info1.ubi < info2.ubi;
}

void merge(std::vector<Info>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid, i = 0, j = 0, k = left;
    std::vector<Info> leftVec(vec.begin() + left, vec.begin() + left + n1);
    std::vector<Info> rightVec(vec.begin() + mid + 1, vec.begin() + mid + 1 + n2);

    while (i < n1 && j < n2) {
        if (compareInfo(leftVec[i], rightVec[j])) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Info>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}