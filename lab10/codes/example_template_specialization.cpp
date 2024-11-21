#include <iostream>
#include <string>
#include <iomanip>

// General template
template <typename T>
class Logger {
public:
    void log(const T& value) {
        std::cout << "Logging value: " << value << std::endl;
    }
};

// Specialized template for `double`
template <>
class Logger<double> {
public:
    void log(const double& value) {
        // Log with 2 decimal places
        std::cout << "Logging double: " << std::fixed << std::setprecision(2) << value << std::endl;
    }
};

// Specialized template for `std::string`
template <>
class Logger<std::string> {
public:
    void log(const std::string& value) {
        std::cout << "Logging string: \"" << value << "\"" << std::endl;
    }
};

// Specialized template for pointers
template <typename T>
class Logger<T*> {
public:
    void log(T* value) {
        if (value) {
            std::cout << "Logging pointer: Address = " << value << ", Value = " << *value << std::endl;
        } else {
            std::cout << "Logging pointer: nullptr" << std::endl;
        }
    }
};

int main() {
    Logger<int> intLogger;
    intLogger.log(42); // General template

    Logger<double> doubleLogger;
    doubleLogger.log(3.14159); // Specialized template for `double`

    Logger<std::string> stringLogger;
    stringLogger.log("Hello, template specialization!"); // Specialized template for `std::string`

    int x = 10;
    Logger<int*> pointerLogger;
    pointerLogger.log(&x); // Specialized template for pointers

    int* nullPointer = nullptr;
    pointerLogger.log(nullPointer); // Specialized template for nullptr

    return 0;
}