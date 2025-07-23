#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    /* data */
public:
    string name;
    double *cgpaPtr;
    Student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    };
    //copy constructor
    Student(Student &obj){
        this->name = obj.name;
        this->cgpaPtr = new double;
        *(this->cgpaPtr) = *(obj.cgpaPtr);
        // this->cgpaPtr = obj.cgpaPtr;
    }
    void getInfo(){
        cout<<"name ; " << name << endl;
        cout<<"cgpa ; " << *cgpaPtr << endl;
    }
};



int main(){
    Student s1("rahul" , 8.2);
    Student s2(s1);
    s1.getInfo();
    s2.getInfo();
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    *(s2.cgpaPtr) = 9.0;
    s2.name = "neha";  
    s1.getInfo();
    s2.getInfo();

    return 0;
}