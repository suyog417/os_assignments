#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

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

    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork Failed");
    }
    else if (pid == 0)
    {
        //Convert integer array to character array
        char args[100];
        for (size_t i = 0; i < n; i++)
        {
            args[i] = arr[i];
        }
        
    }
    
    

    return 0;
}
