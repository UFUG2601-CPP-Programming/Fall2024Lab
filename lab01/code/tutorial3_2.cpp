#include <iostream>

int main() {
    char character = 'a';

    std::cout << "Character: " << character << std::endl;

    int integer = 10;

    std::cout << "Integer: " << integer << std::endl;

    std::cout << "Character + Integer: " << character + integer << std::endl;

    std::cout << "static_cast<int>(Character + Integer): " << static_cast<int>(character + integer) << std::endl;

    std::cout << "static_cast<char>(Character + Integer): " << static_cast<char>(character + integer) << std::endl;

    return 0;
}
