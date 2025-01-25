#include<stdio.h>
//linear seach
int linearSearch(int arr[] , int n , int x){
    // x is the element to be searched
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}
int main(){
    printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");
    // printf("Author : Aditya Om Gupta \nIT-B , 06020803123\n");
    // printf("Author :Satyam Jha \nIT-B , 06620803123\n");
    //taking array input
    int n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    //search #1
    printf("enter the element to be searched: ");
    int x;
    scanf("%d", &x);
    int res = linearSearch(arr , n , x);
    if (res!=-1)
    {
        printf("element found at index : %d \n" ,res );
    }
    else{
        printf("element not found!\n");
    }
    // search #2
    printf("enter the element to be searched: ");
    scanf("%d", &x);
    res = linearSearch(arr , n , x);
    if (res!=-1)
    {
        printf("element found at index : %d " ,res );
    }
    else{
        printf("element not found!\n");
    }
    return 0;
}