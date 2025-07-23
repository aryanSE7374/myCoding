#include <iostream>
#include <stdexcept>  // For std::out_of_range

class Array {
public:
    Array(int size) : size(size), arr(new int[size]) {}

    // Destructor to free allocated memory
    ~Array() {
        delete[] arr;
    }

    // Overloaded subscript operator
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

private:
    int size;
    int* arr;
};

int main() {
    try {
        Array myArray(5);  // Create an array of size 5
        myArray[0] = 10;
        myArray[1] = 20;
        myArray[2] = 30;
        myArray[3] = 40;
        myArray[4] = 50;

        // Attempt to access an element beyond the array size
        std::cout << "Element at index 6: " << myArray[6] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
