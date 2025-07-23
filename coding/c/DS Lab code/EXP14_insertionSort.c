#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    // printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");
    // printf("Author : Shivam Singh \nIT-B , 05920803123\n");
    // printf("Author : Aniket \nIT-B , 06320803123\n");
    // printf("Author : Satyam Jha \nIT-B , 06620803123 \n");
    printf("Author : Aditya Om Gupta \nIT-B , 06020803123 \n");



    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
