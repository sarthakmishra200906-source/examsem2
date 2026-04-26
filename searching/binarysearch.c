#include <stdio.h>

// Sorts the array first so binary search works
void bubblesort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search implementation
int binarysearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (key == arr[mid]) {
            return mid; // Key found
        } else if (key < arr[mid]) {
            r = mid - 1; // Look in the left half
        } else {
            l = mid + 1; // Look in the right half
        }
    }
    return -1; // Not found
}

int main() {
    int n, key;
    printf("Enter array length: ");
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter your key: ");
    scanf("%d", &key);
    
    // Binary search requires a sorted array
    bubblesort(arr, n);
    
    int result = binarysearch(arr, n, key);
    
    if (result != -1) {
        printf("Key found at position %d\n", result + 1);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}