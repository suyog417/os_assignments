#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
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
    int arr[100];
    int n;
    char charArray[n * 11];

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter %d integers : \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, len);
    for (int i = 0; i < n; i++)
    {
        sprintf(charArray + i * 11, "%d\n", arr[i]);
    }
    
    printf("Array sorted...");
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Process Failed...");
    }
    else if (pid == 0)
    {
        wait(NULL);
        execl("child.out", charArray,NULL);
    }
    return 0;
}
