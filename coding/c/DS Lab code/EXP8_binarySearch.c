#include<stdio.h>
//binary seach
// An iterative binary search function.
int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;
        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;
        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }
    // If we reach here, then element was not present
    return -1;
}
int main(){
    printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");
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
    int res = binarySearch(arr , 0 , n-1 , x);
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
    res = binarySearch(arr , 0 , n-1 , x);
    if (res!=-1)
    {
        printf("element found at index : %d \n" ,res );
    }
    else{
        printf("element not found!\n");
    }
    return 0;
}