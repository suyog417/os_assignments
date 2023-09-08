#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h> // Added for wait
#include <unistd.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;

    // Taking input for array size
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    // Taking input for array elements
    printf("Enter %d integers : \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    selectionSort(arr,n);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    char strArray[n*11];
    int spacer = 0;
    for (size_t i = 0; i < n; i++)
    {
        sprintf(strArray+(spacer),"%d\n",arr[i]);
        printf("%d",spacer);
        spacer += 3;
    }

    printf("\nChars : %s",strArray);
    

    return 0;
}
