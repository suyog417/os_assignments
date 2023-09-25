#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 1; i < n - 1; i++)
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
    int n, status, len;
    // Taking input for array size
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    len = n + 1;
    arr[0] = len;
    // Taking input for array elements
    printf("Enter %d integers : \n", n);
    for (int i = 1; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Sorting array
    selectionSort(arr, len);
    // Converting integer array to string array
    char strArray[len * 11];
    for (size_t i = 0; i < len; i++)
    {
        char temp[10];
        sprintf(temp, "%d\n", arr[i]);
        strcat(strArray, temp);
    }
    // Creating a child process
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Process Failed ... ");
    }
    else if (pid == 0)
    {
        execl("./child.out", "child.out", strArray, NULL);
    }
    else
    {
        wait(&status);
        printf("Status : %d", status);
    }
    return 0;
}