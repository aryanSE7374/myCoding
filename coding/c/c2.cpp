#include<iostream>
#include "test.h"

using namespace std;

int main(int argc, char const *argv[])
{
    



    int num;
    cout<<"enter na number :  ";
    cin>>num;
    //commenting out

    #if 0

    int a = 10; int b= 20;
    int* ptra = &a; int* ptrb =  &b;
    
    cout<<a<<" , "<<b<<endl;

    cout<<*ptra<<" , "<<*ptrb<<endl;

    fun(ptra , ptrb);


    cout<<a<<" , "<<b<<endl;

    cout<<*ptra<<" , "<<*ptrb<<endl;

    #endif

    return 0;
}
