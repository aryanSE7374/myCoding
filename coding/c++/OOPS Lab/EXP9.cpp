#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    int length;

public:
    // Constructor
    String(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Copy constructor
    String(const String& s) {
        length = s.length;
        str = new char[length + 1];
        std::strcpy(str, s.str);
    }

    // Overload + operator to concatenate strings
    String operator+(const String& s) {
        char* newStr = new char[length + s.length + 1];
        std::strcpy(newStr, str);
        std::strcat(newStr, s.str);
        return String(newStr);
    }

    // Overload = operator to copy strings
    String& operator=(const String& s) {
        if (this != &s) {
            delete[] str;
            length = s.length;
            str = new char[length + 1];
            std::strcpy(str, s.str);
        }
        return *this;
    }

    // Overload <= operator to compare strings
    bool operator<=(const String& s) {
        return std::strcmp(str, s.str) <= 0;
    }

    // Function to display the length of the string
    int getLength() const {
        return length;
    }

    // Function to convert string to lowercase
    void toLower() {
        for (int i = 0; i < length; i++) {
            str[i] = std::tolower(str[i]);
        }
    }

    // Function to convert string to uppercase
    void toUpper() {
        for (int i = 0; i < length; i++) {
            str[i] = std::toupper(str[i]);
        }
    }

    // Function to display the string
    void display() const {
        std::cout << str << std::endl;
    }
};

// Main function to demonstrate the usage of the class
int main() {
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2;
    s3.display(); // HelloWorld

    s1 = s2;
    s1.display(); // World

    std::cout << (s1 <= s2) << std::endl; // 1 (true)
    std::cout << s1.getLength() << std::endl; // 5

    s1.toLower();
    s1.display(); // world

    s1.toUpper();
    s1.display(); // WORLD

    return 0;
}
