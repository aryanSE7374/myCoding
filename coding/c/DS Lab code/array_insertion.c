#include<stdio.h>
//it will return the updated size of array
int insert(int arr[] , int size , int cap , int x , int pos){
    if (cap<=size){
        return size;
    }
    int i = size-1;
    while (i>=pos)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = x;
    return size+1;
    
}

int main(){

    printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");

    int cap = 10;
    int arr[10] = {3,6,2,8,4}; //created an array of size 5
    int size = 5;
    printf("Initialized Array : " );
    for (int i = 0; i < size; i++)
    {
        printf("%d , ", arr[i]);
    }
    printf("\n");

    size = insert(arr , size , cap , 9 , 1);
    
    printf("Array after insertion : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d , ", arr[i]);
    }
    
}