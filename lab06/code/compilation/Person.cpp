// Person.cpp
#include "Person.h"

// Default constructor implementation
Person::Person() : name("Unknown"), age(0) {}

// Parameterized constructor implementation
Person::Person(const std::string& name, int age) : name(name), age(age) {}

// Member function to display information implementation
void Person::display() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}