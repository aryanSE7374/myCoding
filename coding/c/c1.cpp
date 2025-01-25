#include<iostream>
#include "test.h"

using namespace std;

int main(int argc, char const *argv[])
{
    
    int a = 10; int b= 20;
    int* ptra = &a; int* ptrb =  &b;
    
    cout<<a<<" , "<<b<<endl;

    cout<<*ptra<<" , "<<*ptrb<<endl;

    fun(ptra , ptrb);


    cout<<a<<" , "<<b<<endl;

    cout<<*ptra<<" , "<<*ptrb<<endl;



    return 0;
}

