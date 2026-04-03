#include <stdio.h>

#define MAX_SIZE 100

/*
 * Merge two sorted sub-arrays into a single sorted range.
 * Left sub-array:  arr[left..mid]
 * Right sub-array: arr[mid+1..right]
 */
void merge(int arr[], int left, int mid, int right)
{
    int temp[MAX_SIZE];
    int i = left;
    int j = mid + 1;
    int k = left;

    /* Compare elements from both halves and copy smaller one first. */
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    /* Copy any remaining elements from the left half. */
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    /* Copy any remaining elements from the right half. */
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    /* Copy merged result back into original array segment. */
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

/*
 * Recursive merge sort function:
 * 1) Divide array into two halves
 * 2) Sort each half
 * 3) Merge both sorted halves
 */
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* Utility function to print array elements. */
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX_SIZE];
    int n;
    int i;

    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE)
    {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array using merge sort: ");
    printArray(arr, n);

    return 0;
}
