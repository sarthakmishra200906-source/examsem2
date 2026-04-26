#include <stdio.h>
void linearsearch(int arr[], int n, int key)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("your key is found at pos %d", i + 1);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf(" key is not found ");
    }
}
int main()
{
    int n, key;
    printf("enter your length of array ");
    scanf("%d", &n);
    printf("\nEnter your key : ");
    scanf("%d", &key);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter your element : ");
        scanf("%d", &arr[i]);
    }

    linearsearch(arr, n, key);
    return 0;
}