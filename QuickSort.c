#include <stdio.h>
#include <stdlib.h>

void swap(int * i, int * j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
int partition(int arr[], int firstIdx, int lastIdx)
{
        int pivot = arr[lastIdx];
        int wall = (firstIdx - 1);
        int i;
        for (i = firstIdx; i <= lastIdx - 1; i++)
        {
            if (arr[i] <= pivot)
            {
                wall++;
                swap(&arr[wall], &arr[i]);
            }
        }
        swap(&arr[wall+1], &arr[lastIdx]);
        return (wall + 1);
}
void quickSort(int arr[], int firstIdx, int lastIdx)
{
    if (firstIdx < lastIdx)
    {
        int wall = partition(arr, firstIdx, lastIdx);
        quickSort(arr, firstIdx, wall - 1);
        quickSort(arr, wall + 1, lastIdx);
    }
}
int main()
{
    int n, i;
    printf("Enter the lenght of array: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the value of %d. element: ", i);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n-1);
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}
