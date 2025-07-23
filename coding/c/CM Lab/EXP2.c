#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) x*x*x-2*x-5
int main() {
    // printf("Aryan Shrivasatav , 67 , IT-B\n");
    // printf("Shivam Singh , 59 , IT-B\n");
    double x0, x1, x2, f0, f1, f2, e;
    int i=0,max;
    printf("\n SECANT METHOD");
    up:
    printf("\n\n Enter number x0 : ");
    scanf("%lf",&x0);
    printf("\n\n Enter number x1 : ");
    scanf("%lf",&x1);
    f0=f(x0);
    f1=f(x1);
if((f0-f1)==0){
printf("\n Method does not converge for given inputs"); goto up;
}
    printf("\n Enter permissible error:");
    scanf("%lf",&e);
    printf("\n Enter maximum iterations:");
    scanf("%d",&max);
    do{
    x2=x1-f1*(x1-x0)/(f1-f0);
    f2=f(x2);
    if(f2==f1)
    printf("\n Method does not converge");
    else
    x0=x1;
    x1=x2;
    f0=f1;
    f1=f2;
    i++;
    printf("\n Iteration: %d",i);
    printf(") Root is: %lf",x2);
    printf(", Function value: %lf",f2);
    if(i>=max){
        printf("\n stop");
exit(0);} }
    while(fabs(x0-x1)>=e);
printf("\n Root is: %lf", x2);
return 0;
}