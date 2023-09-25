#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define size 10
int matrixA[size][size];
int matrixB[size][size];
int resultMatrix[size][size];
typedef struct data
{
        int i,j,k;
}matD;

void *mul(void *arg);
void accept(int row,int col, int[size][size]);
int main()
{
        int rowA,colA,rowB,colB;
        printf("Enter the number of rows in matrix A:");
        scanf("%d",&rowA);
        printf("\nEnter the number of columns in matrix A:");
        scanf("%d",&colA);
        printf("\nEnter the number of rows in matrix B:");
        scanf("%d",&rowB);
        printf("\nEnter the number of columns in matrix B:");
        scanf("%d",&colB);
        printf("Enter the elements of A:");
        accept(rowA,colA,matrixA);
        printf("\nEnter the elements of B:");
        accept(rowB,colB,matrixB);
        int thread_size = rowA*colA;
        pthread_t pid[thread_size];
        if(colA!=rowB)
        {
                printf("Matrix A can not be multiplied with Matrix B");
                exit(0);
        }
        int id = 0;

        for(int i=0;i<rowA;i++)
        {
                for(int j=0;j<colA;j++)
                {
                  matD* obj = (matD*)malloc(sizeof(matD));
                  obj->i = i;
                  obj->j = j;
                  obj->k = colA;
                  pthread_create(&pid[id],NULL,mul,(void*)obj);
                  id++;

                }
        }
        id = 0;
        for(int i=0;i<rowA;i++)
        {
                for(int j=0;j<colA;j++)
                {
                        int *result;
                        pthread_join(pid[id],(void **)&result);
                        resultMatrix[i][j] = *result;
                        id++;
                }
        }
        printf("Resultant Matrix\n");
        for(int i = 0;i<rowA;i++)
        {
                for(int j=0;j<colA;j++)
                {
                        printf("%d ",resultMatrix[i][j]);

                }
                printf("\n");
        }



        return 0;

}

void *mul(void *arg)
{
        matD *obj = (matD*)arg;
        int *sum = (int *)malloc(sizeof(int));
        *sum = 0;
        int i = obj->i;
        int j = obj->j;
        int limit = obj->k;
        for(int k=0;k<limit;k++)
        {
                *sum += matrixA[i][k]*matrixB[k][j]; 
        }
        pthread_exit(sum);
        free(sum);
}
void accept(int row,int col,int matrix[size][size])
{
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<col;j++)
                {
                        scanf("%d",&matrix[i][j]);
                }
        }
}
