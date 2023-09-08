#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
        printf("%s\t",token);
        token = strtok(NULL, delimiter);
        i++;
    }
}


int main(int argc, char const *argv[])
{
    char arr[] = "3\n45\n54";
    // int len = sizeof(arr)/sizeof(int);
    int len = atoi(arr);
    int intarr[len];
    printf("Array length is : %d\n",len);
    charArrayToIntArray(arr,intarr,len);
    printf("\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d\t",intarr[i]);
    }
    
    return 0;
}

