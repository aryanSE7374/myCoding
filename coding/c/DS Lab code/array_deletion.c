#include<stdio.h>
//it will return the updated size of array
int delete(int arr[] , int size , int x ){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            for ( ; i < size-1; i++)
            {
                arr[i] = arr[i+1];
            }
            return size-1;
        }
    }
    return size;
    
}

int main(){
    
    printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");

    int cap = 10;
    int arr[10] = {3,9,6,2,8,4}; //created an array of size 6
    int size = 6;
    printf("Initialized Array : " );
    for (int i = 0; i < size; i++)
    {
        printf("%d , ", arr[i]);
    }
    printf("\n");

    size = delete(arr , size , 2);
    
    printf("Array after deletion : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d , ", arr[i]);
    }
    
}