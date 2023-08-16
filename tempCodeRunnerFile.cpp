#include <iostream>
#include <cmath>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void AlgoSort(int A[], int n) {
    for (int k = log2(n); k >= 1; --k) {
        int p = pow(2, k) - 1;
        for (int i = 0; i < p; ++i) {
            for (int j = i; j < n; j += p) {
                // Create a subarray with elements at index i, i + p, i + 2p, ...
                int subarray[p];
                int subarraySize = 0;
                for (int m = i; m < n && subarraySize < p; m += p) {
                    subarray[subarraySize++] = A[m];
                }
                // Sort the subarray using insertion sort
                insertionSort(subarray, subarraySize);
                // Copy sorted subarray back to the original array
                for (int m = i, subIdx = 0; m < n && subIdx < subarraySize; m += p, ++subIdx) {
                    A[m] = subarray[subIdx];
                }
            }
        }
    }
}

int main() {
    int A[] = {9, 3, 7, 5, 1, 8, 4, 2, 6};
    int n = sizeof(A) / sizeof(A[0]);

    AlgoSort(A, n);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
