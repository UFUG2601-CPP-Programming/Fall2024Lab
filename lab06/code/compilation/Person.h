// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
private:
    std::string name;
    int age;

public:
    Person();  // Default constructor
    Person(const std::string& name, int age);  // Parameterized constructor
    void display() const;  // Member function to display information
};

#endif // PERSON_H