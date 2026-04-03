#include <stdio.h>

int position(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (start <= ub && a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }

    {
        int temp = a[lb];
        a[lb] = a[end];
        a[end] = temp;
    }
    return end;
}

void quicksort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = position(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}

int main()
{
    int n;
    printf("enter size of array ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("invalid size\n");
        return 1;
    }

    int a[n];
    printf("enter array elements ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n - 1);

    printf("sorted array is ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}