# Lab 09 C++ Inheritance and Polymorphism

## Important Notes
- **Please finish the problems in the contest "Lab09" in OJ by the end of this week (2024-11-17 23:59:59).**

## Lab Description
In this lab you will get experience with some of the implementation issues and conceptual details of inheritance. Inheritance is a mechanism for increasing the reusability and reliability of C++ code. It is worth mentioning that inheritance is a fundamental characteristic of all object oriented programming languages. 
The inheritance can be described as an is-a relationship. For example, a triangle is a shape, or a student is a scholar. 
Our goal is to give you a glimpse of the functionality of inheritance.

## Syntax of Inheritance in C++
```cpp
class  derived_class_name : access-specifier  base_class_name
{
       //    body ....
};
```

The inheritance allows us to implement all the ```common``` features of our objects in a ```base``` class. When we derive a class from the base class, the derived class will inherit the common features implemented in the base, so we will need to implement only the features specific to the derived class. This approach leads to a leaner and easier to maintain code.

Inheritance is an is-a relation between the ```Base``` and the ```Derived``` classes.

## Modes of Inheritance in C++
Mode of inheritance controls the access level of the inherited members of the base class in the derived class. In C++, there are 3 modes of inheritance:
- Public Mode
- Protected Mode
- Private Mode

### Summary of Comparison
| Inheritance/Base Members |  Public Members | Protected Members | Private Members |
|----------|:--------:|---------:|---------:|
| Public   | Public   | Protected   | Inaccessible |
| Protected  | Protected   | Protected   | Inaccessible |
| Private  | Private   | Private   | Inaccessible |


### Public Inheritance
```cpp
#include <iostream>
using namespace std;

class Shape {
   public:
       void setWidth(int w)
       {
           width = w;
       }
       void setHeight(int h)
       {
           height = h;
       }
   protected:
       int width;
       int height;
};

class Rectangle: public Shape {
   public:
       int getArea()
       {
          return (width * height);
       }
};

int main() {
   Rectangle rect;
   rect.setWidth(5);
   rect.setHeight(7);
   cout << "Area of the rectangle is: " << rect.getArea() << endl;
   return 0;
}
```
> `Output：Area of the rectangle is: 35`


### Protected Inheritance
_Protected inheritance makes the parent class's protected and public members become protected members in the subclass, accessible by the subclass itself and its derived classes, but not by external programs. The private members of the parent class are not inherited._
```cpp
class Parent 
{
 public:
   void publicFunc() 
   {
     std::cout << "This is a public function in Parent class." << std::endl;
   }
 protected:
   void protectedFunc() 
  {
     std::cout << "This is a protected function in Parent class." << std::endl;
  }
private:
   void privateFunc() 
   {
     std::cout << "This is a private function in Parent class." << std::endl;
   }
};

class Child : protected Parent 
{
 public:
   void accessParentFunc() 
   {
     publicFunc(); // accessible
     protectedFunc(); // accessible
     // privateFunc(); // compiler error
   }
};

int main() 
{
  Child c;
  c.accessParentFunc();
  return 0;
}
```

### Private Inheritance
_Private inheritance inherits the public and protected members of the base class as private members in the derived class, preventing derived class objects from accessing the public and protected members of the base class._
```cpp
#include <iostream>

class Base {
public:
   void public_func() {
       std::cout << "Base public function." << std::endl;
   }
protected:
   void protected_func() {
       std::cout << "Base protected function." << std::endl;
   }
private:
   void private_func() {
       std::cout << "Base private function." << std::endl;
   }
};

class Derived : private Base {
public:
   void call_base_funcs() {
       // Private inheritance makes all members 
       // of the base class private members, 
       // which cannot be accessed directly.
       // public_func(); // compiler error
       // protected_func(); // compiler error
       // private_func(); // compiler error

       // indirectly access the base class members 
       // through the member functions of the derived class.
       Base::public_func(); 
       Base::protected_func(); 
       // Private member functions of the base class cannot be called, 
       // even through indirect access.
       // Base::private_func(); // compiler error
   }
};

int main() {
   Derived d;
   d.call_base_funcs();
   return 0;
}
```

### Changing Access Permissions
> The using keyword can change the access permissions of base class members in the derived class, such as changing public to private or protected to public.

> <code style="color: red;">Note: using can only change the access permissions of public and protected members in the base class. It cannot change the access permissions of private members, because private members in the base class are not visible in the derived class and cannot be used. Therefore, private members in the base class cannot be accessed in the derived class under any circumstances.</code>

#### 1. Altering protected members in Base class to public members in Derived class.
```cpp
class Animal {
protected:
   std::string m_name;
};

class Cat : public Animal {
public:
   using Animal::m_name; // here!!!

   void printName() {
       std::cout << "My name is " << m_name << std::endl;
   }
};

int main() {
   Cat cat;
   cat.m_name = "Tom"; // directly access
   cat.printName();
   return 0;
}
```

#### 2. Altering public members in Base class to protected members in Derived class.
```cpp
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
```

### 3. Name Hiding in C++
> Hiding occurs when a member in the derived class is used instead of the one inherited from the base class.

```cpp
class Base {
public:
   int var;
   void func();
};

class Derived : public Base {
public:
   int var;
   void func();
};
```

We can tackle this with `using` keyword.
```cpp
class Derived : public Base {
public:
   int var;
   void func();
   void test() {
       Base::var = 10;
       Base::func();
   }
};
```
Or
```cpp
class Derived : public Base {
public:
   using Base::var;
   using Base::func;
   int var;
   void func();
   void test() {
       Base::var = 10;
       Base::func();
   }
};
```

### 4. Using Pointers to Bypass Access Restrictions to Access Private and Protected Member Variables
> Pointers can bypass the compiler's access restrictions and directly access data in memory. 
```cpp
#include<iostream>
using namespace std;

class A {
private:
   int num;
public:
   void setNum(int n) {
       num = n;
   }
   int getNum() {
       return num;
   }
};

int main() {
   A a;
   int *p = (int *)&a; // convert object addr to int pointer
   *p = 10; // access here!
   cout << a.getNum() << endl; // output is 10
   return 0;
}
```
> <code style="color: red;">However, this method is not recommended in practice because it breaks the encapsulation of the class, is unsafe, and increases code maintenance difficulty and instability.</code>

## Virtual Function
> Changing the behavior of a parent class is done through `virtual` functions. 

To achieve this, there are two steps: 
- Defining in the parent class  
- Modifying in the child class. 
> The key point in defining the parent class is to label the member function as `virtual`.

```cpp
class Person {
 protected:
    std::string name;
 
 public:
     Person(const std::string name) :name{ name } {
         std::cout << "Create person = " << name << std::endl;
     }
 
    virtual void introduction() {
        std::cout << "My name is " << name << std::endl;
    }
};

class Friends :public Person {
    std::string nickname;
 public:
    Friends(const std::string name, const std::string nickname) : Person(name), nickname{ nickname }{
        std::cout << "Create person = " << name << " with nickname " << nickname << std::endl;
    }

    void hi() {
        std::cout << "My nickname is " << nickname << std::endl;
    }

    void introduction() override {
        std::cout << "From Friends -> my name is " << name << std::endl;
    }
};

int main() {
    Friends f{"zhangsan", "laozhang"};
    f.introduction();
    f.hi();

    return 0;
}
```

> Output:  
Create person = zhangsan  
Create person = zhangsan with nickname laozhang  
From Friends -> my name is zhangsan  
My nickname is laozhang


### Summary of Function Overloading vs Function Overriding in C++
|  |  Function Overloading | Function Overriding |
|----------|:--------:|---------:|
| Working   | Compile time   | Run time   | 
| Function Name  | Same   | Same   | 
| Return Value  | Can change   | Same   | 
| Parameters  | Can change   | Same   | 

> <code style="color: red;">_Note: Both constructor and destructor CANNOT be inhterited by derived classes!_</code> 

## Polymorphism
> _Polymorphism refers to the ability of a base class pointer to point to an object of a derived class, allowing manipulation of derived class objects through base class pointers or references._

> Polymorphism focuses on behavior inheritance.

### Abstract Class and Interface
```cpp
#include <iostream>
using namespace std;
// geometric graphics
class Shape {
public:
    // area computation behavior interface
    virtual float area() = 0;

    // perimeter computation behavior interface
    virtual float perimeter() = 0;
};

class Rect :public Shape {
    float x, y;
public:

    Rect(float x, float y) :x{ x }, y{ y } {
    }

    float area() override {
        return x * y;
    }

    float perimeter() override {
        return 2 * (x + y);
    }
};

void calc(Shape& shape) {
    cout << "Area of this shape is " << shape.area() << endl;
    cout << "Perimeter of this shape is " << shape.perimeter() << endl;
}

int main() {
    Rect r{ 2,3 };
    calc(r);

    return 0;
}

// Ouput
// Area of this shape is 6
// Perimeter of this shape is 10
```
> _Abstract class primarily defines interfaces and ensures that subclasses must implement those interfaces, while also preventing users from directly creating objects of the class._



### One more thing -- Virtual Destructor

**Question: Why the destructor of the `base` class needs to be virtual?** 
```cpp
#include <iostream>
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}
```
> Output:  
Base destructor called  
Derived destructor called  

> Analysis:  
Base class pointer points to a derived class object supported by polymorphism  
`delete ptr` will invoke the destructor of the derived class  
The destructor of the derived class automatically calls the destructor of the base class, ensuring the complete release of the derived class object.  
If the destructor is not declared as a virtual function, <code style="color: red;">the compiler enforces static binding</code>.  
When deleting a base class pointer, only the destructor of the base class is called  
This can lead to incomplete destruction of the derived class object, potentially causing security issues such as <code style="color: red;">resource leaks</code>.


## Reference
- https://www.runoob.com/cplusplus/cpp-inheritance.html
- https://github.com/cme212/course/blob/master/notes/lecture-07/inheritance.md
- https://www.geeksforgeeks.org/inheritance-in-c/
- https://mp.weixin.qq.com/s/ulX4Msbp-rONsCt9J2wz_g
- https://mp.weixin.qq.com/s/8o12URippULLLgNKZDldCg
