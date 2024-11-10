#include <iostream>

class Person {
public:
   void sayHello() {
       std::cout << "Hello!" << std::endl;
   }
};

class Student : public Person {
protected:
   using Person::sayHello; // here!!!

public:
   void sayHello(int grade) {
       std::cout << "Hello! My grade is " << grade << std::endl;
   }
};

int main() {
   Student student;
   student.sayHello(); // compiler error!!!
   student.sayHello(90); // overload member function
   return 0;
}