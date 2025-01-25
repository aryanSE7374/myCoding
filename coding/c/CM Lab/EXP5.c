// PRACTICAL 5
// C code for interpolating using the divided difference method:
#include <stdio.h>
int main(){
    // printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");
    printf("Author : Aniket \nIT-B , 06320803123\n");
    int n;
    printf("Enter the number of data points: \n");
    scanf("%d", &n);
    double x[n], y[n];
    printf("Enter the data points in format (x,y):\n");
    for(int i = 0; i < n; i++) {
        printf("x[%d]= ", i);
        scanf("%lf", &x[i]);
        printf("y[%d]= ", i);
        scanf("%lf", &y[i]);
    }
    double x_val;
    printf("\nEnter the value of x at which you want to interpolate: ");
    scanf("%lf", &x_val);
    double result = 0;
    double f[n][n];
    for (int i = 0; i < n; i++) {
        f[i][0] = y[i];
    }
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < n - j; i++) {
            f[i][j] = (f[i + 1][j - 1] - f[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    for(int j = 0; j < n; j++) {
        double term = f[0][j];
        for(int i = 0; i < j; i++) {
            term *= (x_val - x[i]);
        }
        result += term;
    }
    double interpolated_value = result;
    printf("Interpolated value at x=%.2lf is %.2lf \n", x_val, interpolated_value);
    return 0;
}








// int main(){
// int n;
// printf("Enter the number of data points: \n");
// scanf("%d", &n);
// double x[n],y[n];
// printf("Enter the data points in format (x,y):\n");
// for(int i=0;i<n;i++){
// printf("x[%d]="i);
// scanf("%If",8x[1):
// printf("y[9%d]= "i);
// scanf("%|f", &y [i);
// }
// double x val;
// printf("\n Enter the value of x at which you want to interpolate= ");
// scanf("%lf", &x_val);
// double result-0;
// double f[n]ln);
// for(int i=0;i<n;it+){
// f[iJ[0]-=y[i);
// }
// for(int j=1;j<n;j++)\
// for(int i=0;i<n-j;it++){
// f[J0]-(f[i+1)[j-1]-f[][j-1)/(x[i+j]-x(i):
// }
// }
// for(int j-0;j<n;j++){
// double term=f[o][i];
// for(int i=0;i<j;i++){
// term *= (x_val-x[i]);
// }
// result += term;
// }
// double interpolated_value=result;
// printf("Interpolated value at x=%lf is %if \n"x_val,interpolated_value);
// return 0;
// }












// -----------------------------------------------------------------------
// #include<stdio.h>
// int main(){
//     // printf("Shivam Singh , 59 , IT-B\n");
//     printf("Aryan Shrivasatav , 67 , IT-B\n");
//     printf("NEWTONS DIVIDED DIFFERENCE\n");
//     double x[100],y[100], xi,term, result=0.0;
//     int n;
//     printf("enter max no of points = ");
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         printf("Value of x[%d] = ",i);
//         scanf("%lf", &x[i]);
//         printf("Value of y[%d] = ",i);
//         scanf("%lf", &y[i]);
//     }
//     printf("\npoint where interpolated value is to be found = ");
//     scanf("%lf",&xi);
//     for(int i=0;i<n;i++){
//         term=y[i];
//         for(int j=0;j<n;j++){
//             if(i!=j){
//                 term*=(xi-x[j])/(x[i]-x[j]);
//             }
//         }
//         result+=term;
//     }
//     printf("\nInterpolated Value at x = %lf is y: %lf", xi, result);
//     printf("\ninterpolated Polynomial :~");
//     printf("\nP(x) =");
//     for(int i=0;i<n;i++){
//         printf(" (%lf)", y[i]);
//         for(int j=0;j<n;j++){
//             if(i!=j){
//                 printf("*(x-%lf)/(%lf-%lf)",x[j],x[i],x[j]);
//         }
//         }
//         if(i<n-1){
//             printf(" +");
//         }
//     }
//     return 0;
// }