#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    
    int pid = getpid();
    int ppid = getppid();
    printf("%d", pid);
    printf("%d", ppid);
    int forkId = fork();
    if (forkId == 0)
        for (size_t i = 0; i < 100; i++)
        {

            printf("child: \n%d\n", forkId);
        }
    else{

    int x;
    wait(&x);
        for (size_t i = 0; i < 100; i++)
        {

            printf("parent: \n%d\n", forkId);
        }
    }
    return 0;
}
