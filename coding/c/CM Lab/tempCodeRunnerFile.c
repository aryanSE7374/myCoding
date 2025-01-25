#include <stdio.h>
#include <math.h>
#define n 3 

void printMatrix(double mat[n][2*n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n; j++){
            printf("%0.2f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(double mat[n][2*n]){
    for(int i = 0; i < n; i++){
        double pivot = mat[i][i];
        
        // Divide the row by the pivot
        for(int j = 0; j < 2 * n; j++){
            mat[i][j] /= pivot;
        }
        
        // Make other rows zero in the current column
        for(int k = 0; k < n; k++){
            if(k != i){
                double factor = mat[k][i];
                for(int j = 0; j < 2 * n; j++){
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
    }
}

int main(){
    printf("Aryan Shrivasatav , 67 , IT-B\n");
    // printf("Shivam Singh , 59 , IT-B\n");
    // printf("Author : Aniket \nIT-B , 06320803123\n");
    printf("Gauss Jordan Method \n");

    double matrix[n][2*n];
    
    // Input the n x n part of the matrix
    printf("Enter the matrix: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Enter value for [%d][%d]=", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
    
    // Initialize the identity matrix in the augmented matrix
    for(int i = 0; i < n; i++){
        for(int j = n; j < 2 * n; j++){
            if(i == (j - n)){
                matrix[i][j] = 1.0;
            } else {
                matrix[i][j] = 0.0;
            }
        }
    }
    
    printf("\nAugmented matrix (A:I) before Gauss Jordan Elimination:\n");
    printMatrix(matrix);
    
    gaussJordan(matrix);
    
    printf("\nAugmented matrix after Gauss Jordan Elimination:\n");
    printMatrix(matrix);
    
    printf("Inverse matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = n; j < 2 * n; j++){
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}