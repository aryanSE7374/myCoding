#include <iostream>
#include <string>

// Template function inside a class to calculate the square of a number
template <typename T>
class SquareCalculator {
public:
    T calculateSquare(T number) {
        return number * number;
    }
};

int main() {
    // Instances of SquareCalculator for different data types
    SquareCalculator<int> intCalculator;
    SquareCalculator<float> floatCalculator;
    SquareCalculator<double> doubleCalculator;

    int intNum = 5;
    float floatNum = 3.5f;
    double doubleNum = 4.5;

    std::cout << "Square of " << intNum << " is: " << intCalculator.calculateSquare(intNum) << std::endl;
    std::cout << "Square of " << floatNum << " is: " << floatCalculator.calculateSquare(floatNum) << std::endl;
    std::cout << "Square of " << doubleNum << " is: " << doubleCalculator.calculateSquare(doubleNum) << std::endl;

    return 0;
}
