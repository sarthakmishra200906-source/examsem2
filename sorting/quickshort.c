#include <stdio.h>

// Helper function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition logic
int partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        // Move start right while elements are <= pivot
        while (a[start] <= pivot && start < ub) {
            start++;
        }
        // Move end left while elements are > pivot
        while (a[end] > pivot) {
            end--;
        }
        // Swap if pointers haven't crossed
        if (start < end) {
            swap(&a[start], &a[end]);
        }
    }
    // Place pivot in correct position
    swap(&a[lb], &a[end]);
    return end;
}

// QuickSort recursive function
void quickSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}