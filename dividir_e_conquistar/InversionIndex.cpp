#include <iostream>
#include <vector>

int merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int inversionCount = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inversionCount += (n1 - i); // Count inversions
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inversionCount;
}

int mergeSort(std::vector<int>& arr, int left, int right) {
    int inversionCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversionCount += mergeSort(arr, left, mid); // Count inversions in left half
        inversionCount += mergeSort(arr, mid + 1, right); // Count inversions in right half
        inversionCount += merge(arr, left, mid, right); // Count inversions during merge
    }
    return inversionCount;
}