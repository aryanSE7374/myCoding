#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#define e 0.00000001
//trancidental eqn
#define f(x)  x*cos(x) - 1

int main()
{
    printf("Aryan Shrivasatav , 67 , IT-B\n");
    float x0,x1,x2,f0,f1,f2;
    int i= 0, maxitr ;
    up: 
    printf("enter the first assumed root: ");
    scanf("%f" , &x0);
    printf("enter the second assumed root: ");
    scanf("%f" , &x1);
    printf("enter the maximum iteration:  ");
    scanf("%d" , &maxitr);
    f0=f(x0);
    f1=f(x1);
    if(f0*f1>0)
    {
        printf("eror \n");
        goto up;
    }
    do{
      x2 = (x0+x1)/2;
      f2=f(x2);
      if(f0*f2<0) {
          x1=x2;
      }
      else{
          x0=x2;
      }
      i++;
      if(i>maxitr){
          printf("\nstopped");
          exit(0);
      }
      printf("number of iteration = %d\n",i);
      printf("root = %f\n", x2);
      printf("value of function = %f\n",f(x2));
      
    }while(fabs(x0-x1)>=e);
    
    
    return 0;
}