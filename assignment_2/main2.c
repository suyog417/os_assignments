#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>  // Added for wait
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

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter %d integers : \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int len = n;  // No need to divide sizeof(arr) by sizeof(arr[0])
    selectionSort(arr, len);
    for (size_t i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    char charArray[n * 11];

    for (int i = 0; i < n; i++)
    {
        sprintf(charArray + i * 11, "%d\n", arr[i]);
    }

    printf("Array sorted...\n");
    
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Process Failed...\n");
    }
    else if (pid == 0)
    {
        // In the child process, execute a program (e.g., "child.out") and pass charArray as an argument
        execl("./child.out", "child.out", charArray, NULL);
    }
    else
    {
        // In the parent process, wait for the child to complete
        wait(NULL);
    }
    return 0;
}
