#include <iostream>

// Template class to compare two numbers
template <typename T>
class Compare {
private:
    T num1, num2;

public:
    // Constructor
    Compare(T a, T b) : num1(a), num2(b) {
        std::cout << "Constructor called. Numbers are " << num1 << " and " << num2 << std::endl;
    }

    // Destructor
    ~Compare() {
        std::cout << "Destructor called. Compare object is being deleted." << std::endl;
    }

    // Function to find the bigger number
    T bigger() {
        return (num1 > num2) ? num1 : num2;
    }
};

int main() {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;
    Compare<int> intCompare(a, b);
    std::cout << "The bigger number is: " << intCompare.bigger() << std::endl;

    float x, y;
    std::cout << "Enter two float numbers: ";
    std::cin >> x >> y;
    Compare<float> floatCompare(x, y);
    std::cout << "The bigger number is: " << floatCompare.bigger() << std::endl;

    return 0;
}
