#include <iostream>
#include <fstream>

// Define a simple structure
struct Data {
    int id;
    double value;
    char name[50];
};

int main() {
// Create an instance of Data
    Data writeData = {1, 99.99, "Example"};

    // Write the structure to a binary file
    std::ofstream outputFile("data.bin", std::ios::binary);
    if (!outputFile) {
        std::cerr << "Unable to open file for writing";
        return 1;
    }

    // Write the structure to the file
    outputFile.write(reinterpret_cast<char*>(&writeData), sizeof(writeData));
    outputFile.close();

    // Create a new instance to read the data into
    Data readData;

    // Read the structure from the binary file
    std::ifstream inputFile("data.bin", std::ios::binary);
    if (!inputFile) {
        std::cerr << "Unable to open file for reading";
        return 1;
    }

    // Read the data from the file
    inputFile.read(reinterpret_cast<char*>(&readData), sizeof(readData));
    inputFile.close();

    // Display the read data
    std::cout << "ID: " << readData.id << std::endl;
    std::cout << "Value: " << readData.value << std::endl;
    std::cout << "Name: " << readData.name << std::endl;

    return 0;
}