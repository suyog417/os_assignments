#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void charArrayToIntArray(const char *charArray, int *intArray, int n)
{
    const char *delimiter = "\n";
    char *token;
    int i = 0;

    token = strtok(charArray, delimiter);

    while (token != NULL && i < n)
    {
        intArray[i] = atoi(token);
        i++;
        token = strtok(NULL, delimiter);
    }
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int target;
    int intarr[100];
    int n = 0;
    int len = sizeof(argv) / sizeof(argv[0]);
    for (int i = 0; i < len; i++)
    {
        if (argv[i] == '\n')
        {
            n++;
        }
    }

    int intArray[n];
    charArrayToIntArray(argv, intArray, n);

    printf("Enter the element you want to search : ");
    scanf("%d", &target);
    int result = binarySearch(intArray, 0, n - 1, target);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
}
