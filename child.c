#include<stdio.h>


int binarySearch(int a[],int key){
    int start = 0;
    int end = sizeof(a) / sizeof(a[0]) -1;
    int mid = start + end /2;
    while(start < end){
        if(a[mid] == key){
            return mid;
        }
        else if(a[mid] > key){
            mid = start +1;
        }
        else{
            mid = end -1;
        }
    }
}
// int binarySearch(int a[], int beg, int end, int val)    
// {    
//     int mid;    
//     if(end >= beg)     
//     {        mid = (beg + end)/2;    
//         if(a[mid] == val)    
//         {                 
//             return mid+1;    
//         }    
//         else if(a[mid] < val)     
//         {  
//             return binarySearch(a, mid+1, end, val);    
//         }    
//         else     
//         {  
//             return binarySearch(a, beg, mid-1, val);    
//         }          
//     }    
//     return -1;     
// }   
int main(int argc, char const *argv[])
{
    int arr[] = {10,50,30,45,97,97,90,45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = binarySearch(arr,30);
    printf("%d",res);
    return 0;
}