#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void charArrayToIntArray(char *charArray, int *intArray, int n)
{
    const char *delimiter = "\n";
    char *token;
    int i = 0;

    token = strtok(charArray, delimiter);

    while (token != NULL && i < n)
    {
        int temp = atoi(token);
        intArray[i] = temp;
        token = strtok(NULL, delimiter);
        i++;
    }
}

int binarySearch(int *arr, int left, int right, int target)
{
    while (left <= right)
    {
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

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <element1> <element2> ... <elementN>\n", argv[0]);
        return 1;
    }
    // int n = argc;
    int len = atoi(argv[1]);
    int intArray[len];
    int target;
    charArrayToIntArray(argv[1],intArray,len);
    printf("Sorted Array : ");
    for (size_t i = 1; i < len; i++)
    {
        printf("%d\t",intArray[i]);
    }
    
    printf("\nChild Process : ");
    printf("\nEnter the element you want to search : ");
    scanf("%d", &target);
    int result = binarySearch(intArray, 0, len - 1, target);

    if (result != -1)
    {
        printf("Element found at index %d\n", result-1);
    }
    else
    {
        printf("Element not found\n");
    }
       
    return 0;
}