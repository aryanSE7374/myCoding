// PRACTICAL 4
#include<stdio.h>
int main(){
    printf("Aniket , 63 , IT-B\n");
    printf("LAGRANGE INTERPOLATION\n");
    double x[100],y[100], xi, term, result=0.0; int n;
    printf("enter max no of points = ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nValue of x[%d] = ",i);
        scanf("%lf",&x[i]);
        printf("\nValue of y[%d] = ",i);
        scanf("%lf",&y[i]);
    }
    printf("\npoint where interpolated value is to be found = ");
    scanf("%lf", &xi);
    for(int i=0;i<n;i++){
        term=y[i];
        for(int j=0;j<n;j++){
            if(i!=j){
            term*=(xi-x[j])/(x[i]-x[j]);
            }
        }
        result+=term;
    }
    printf("\ninterpolated Value at x = %lf is y: %lf", xi, result);
    printf("\nInterpolated Polynomial :~");
    printf("\nP(x) =");
    for(int i=0;i<n;i++){
        printf(" (%lf)", y[i]);
        for(int j=0;j<n;j++){
            if(i!=j){
                printf("*(x-%lf)/(%lf-%lf)",x[j],x[i],x[j]);
            }
        }
        if(i<n-1){
            printf(" +");
        }
    }
    return 0;
}