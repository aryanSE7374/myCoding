#include <stdio.h>

int main() {

    //m,n rows and columns of the first matrix
    //p,q rows and columns of the second mattrix
    //c,d are loop variables for iteration of matrices
    //k: iterator variable
    printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");

    int m, n, p, q, c, d, k;
    int multiply[10][10], sum = 0;

    printf("Enter the number of rows in the first matrix: ");
    scanf("%d", &m);
    printf("Enter the number of columns in the first matrix: ");
    scanf("%d", &n);

    int first[m][n];

    printf("Enter the elements of the first matrix:\n");
    for (c = 0; c < m; c++) {
        for (d = 0; d < n; d++) {
            scanf("%d", &first[c][d]);
        }
    }


    printf("Enter the number of rows in the second matrix: ");
    scanf("%d", &p);
    printf("Enter the number of columns in the second matrix: ");
    scanf("%d", &q);
    
    int second[p][q];


    if (n != p) {
        
        printf("Matrix multiplication is not possible.\n");
    } else {
        printf("Enter the elements of the second matrix:\n");
        for (c = 0; c < p; c++) {
            for (d = 0; d < q; d++) {
                scanf("%d", &second[c][d]);
            }
        }

        // Matrix multiplication
        for (c = 0; c < m; c++) {
            for (d = 0; d < q; d++) {
                for (k = 0; k < p; k++) {
                    sum += (first[c][k] * second[k][d]);
                }
                multiply[c][d] = sum;
                sum = 0;
            }
        }

        // Display the result
        printf("\nThe product of the entered matrices is:\n");
        for (c = 0; c < m; c++) {
            for (d = 0; d < q; d++) {
                printf("%d\t", multiply[c][d]);
            }
            printf("\n");
        }
    }

    return 0;
}
