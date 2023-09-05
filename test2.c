#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[100];
    int n;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    printf("Enter %d integers : \n",n);
    for(int i = 0; i < n;i++){
        scanf("%d",&arr[i]);
    }
    char args[100];
    for (size_t i = 0; i < n; i++)
    {
        args[i] = arr[i];
        printf("%c",args[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        // printf("%c",args[i]);
        // int temp = args[i];
        // printf("%d",temp);
    }
    return 0;
}
