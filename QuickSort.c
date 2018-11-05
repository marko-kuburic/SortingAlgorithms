#include <stdio.h>
#include <stdlib.h>

void swap(int * i, int * j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
void readData(int arr[], int n)
{
    for (int i = 0; i < n;i++)
    {
        printf("\nEnter the value of %d. element: ", i);
        scanf("%d", &arr[i]);
    }
}
int partition(int arr[], int first, int last){
        int pivot = arr[last];
        int wall = (first - 1);
        int i;
        for(i = first; i <= last - 1; i++){
            if(arr[i] <= pivot){
                wall++;
                swap(&arr[wall], &arr[i]);
            }
        }
        swap(&arr[wall+1], &arr[last]);
        return (wall + 1);
}
void quickSort(int arr[], int first, int last)
{
    if(first < last){
        int wall = partition(arr, first, last);
        quickSort(arr, first, wall - 1);
        quickSort(arr, wall + 1, last);

    }
}
void displayData(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    int n, i;
    printf("Enter the lenght of array: ");
    scanf("%d", &n);
    int arr[n];
    readData(arr, n);
    quickSort(arr, 0, n-1);
    displayData(arr, n);

    return 0;
}
