#include <iostream>
#include <string>

int main(){
    // Declare and assign values to different data types
    int intNumber = 1;
    float floatNumber = 0.114514f;
    long int longNumber = 114514;
    char chr = 's';
    std::string str = "Hello World!";
    
    // Print the variable in std::cout
    std::cout << "The value of defined integer is: " << intNumber << std::endl;
    std::cout << "The value of defined float is: " << floatNumber << std::endl;
    std::cout << "The value of defined long is: " << longNumber << std::endl;
    std::cout << "The value of defined char is: " << chr << std::endl;
    std::cout << "The value of defined string is: " << str << std::endl;

    return 0;
}