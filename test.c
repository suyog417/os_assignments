#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {10,50,6,76,694,354,87,35,87,34,687,340};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("%d",len);
    return 0;
}
