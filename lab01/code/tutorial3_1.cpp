#include <iostream>

int main() {
    int i = 0;

    std::cout << "result: " << (i++ < 2) << std::endl;
    std::cout << "result: " << (i++ < 2) << std::endl;
    std::cout << "result: " << (i++ < 2) << std::endl; 

    i = 0;

    std::cout << "result: " << (++i < 2) << std::endl;
    std::cout << "result: " << (++i < 2) << std::endl;
    std::cout << "result: " << (++i < 2) << std::endl; 
    
    return 0;
}
