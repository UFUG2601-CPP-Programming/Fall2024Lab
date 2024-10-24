#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    // Default constructor initializing fields to non-zero values
    Person() : name("John Doe"), age(30) {
        // Here, the name is initialized to "John Doe" and age to 30
        // These are not zero but specific default values.
    }

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Creating an object of Person using the default constructor
    Person person;
    person.display();  // Outputs: Name: John Doe, Age: 30

    return 0;
}