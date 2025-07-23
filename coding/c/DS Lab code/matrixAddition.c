#include<stdio.h>

int main()
{

    printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");
    //matrix input 
    int r1,c1;
    int r2,c2;
    // aray1
    printf("input for Array1: \n");
    printf("enter the number of rows: ");
    scanf("%d",&r1);
    printf("enter the number of columns: ");
    scanf("%d",&c1);
    // aray2
    printf("input for Array2: \n");
    printf("enter the number of rows: ");
    scanf("%d",&r2);
    printf("enter the number of columns: ");
    scanf("%d",&c2);
    if (r1==r2 && c1==c2)
    {
        //Array1
        printf("input for Array1: \n");
        int mat1[r1][c1] ;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("enter the element at (%d,%d): ", i,j );
                scanf("%d", &mat1[i][j]);
            }
        }
        //Array2
        printf("input for Array2: \n");
        int mat2[r2][c2] ;
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("enter the element at (%d,%d): ", i,j );
                scanf("%d", &mat2[i][j]);
            }
        }

        //perform matrix additoin

        int resMat[r1][c1];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j <c1; j++)
            {
                resMat[i][j] = mat1[i][j] + mat2[i][j] ;
            }
        }

        //print the result matrix
        printf("Result matrix after addition: \n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("%d\t", resMat[i][j]);
            }
            printf("\n");
        }

    }
    else{
        printf("can't add two matrices whose rows and columns are not identical! \n");
    }
    return 0;
}
