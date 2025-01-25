#include<iostream>
#define PI 3.14159265359
using namespace std;
class rectangle
{
    private:
        float length , breadth;
    public:
        //setter for length
        void set_length(int len){
            length = len;
        }
        //getter for length
        float get_length(){
            return length;
        }
        //setter for breadth
        void set_breadth(int bred){
            breadth = bred;
        }
        //getter for breadth
        float get_breadth(){
            return breadth;
        }
        float perimeter(){
            return 2*(length + breadth);
        }
        float area(){
            return length*breadth;
        }

};

class circle
{
    private:
        float radius;
    public:
        //setter for radius
        void set_radius(int rad){
            radius = rad;
        }
        //getter for radius
        float get_radius(){
            return radius;
        }
        float perimeter(){
            return 2*PI*radius;
        }
        float area(){
            return PI*radius*radius;
        }
};




int main(){
    rectangle rect;
    rect.set_length(12.0);
    float len = get_length();
    cout<<len;
    return 0;
}