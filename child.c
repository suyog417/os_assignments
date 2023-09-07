#include <stdio.h>

int binarySearch(int a[], int key)
{
    int start = 0;
    int end = sizeof(a) / sizeof(a[0]) - 1;
    int mid;
    printf("Loop initiated !!");
    while (start < end)
    {
        mid = start + end / 2;
        printf("Loop");
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            start = mid + 1;
            printf("Mid++\n");
        }
        else
        {
            start = mid - 1;
            printf("Mid--\n");
        }
    }
    return -1;
}

int search(int low, int high, int mid, int array[], int key)
{
    while (low <= high)
    {
        if (array[mid] < key)
            low = mid + 1;
        else if (array[mid] == key)
        {
            printf("%d found at location %d\n", key, mid + 1);
            break;
        }
        else
            high = mid - 1;
        mid = (low + high) / 2;
    }
    if (low > high)
        printf("Not found! %d isn't present in the list\n", key);
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 50, 30, 45, 97, 97, 90, 45};
    int key;
    printf("Enter the element to search : ");
    scanf("%d",&key);
    int res = binarySearch(arr, 30);
    printf("%d", res);
    return 0;
}