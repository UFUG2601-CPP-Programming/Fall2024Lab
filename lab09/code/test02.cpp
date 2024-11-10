#include <iostream>

class Base {
public:
    int public_member;

    Base() : public_member(0) {}
    
    void public_method() {
        std::cout << "Base public method" << std::endl;
    }
};

class Derived : public Base {
public:
    // 使用using将基类的公共成员引入派生类
    using Base::public_member;
    using Base::public_method;

protected:
    // 将引入的public成员转为protected
    int protected_member = public_member;  // 继承的public成员转为protected
    void protected_method() {              // 继承的public方法转为protected
        public_method();  // 调用基类的public方法
    }
};

int main() {
    Derived d;
    
    // 直接访问基类的public成员，派生类的protected成员无法访问
    d.public_member = 10;  // 仍然是public_member, 仍然可以在派生类中访问
    
    d.public_method();     // 派生类继承了基类的public方法
    
    // protected_member 和 protected_method 无法在main函数中访问
    // d.protected_member = 20;  // 错误：protected_member 是protected
    // d.protected_method();     // 错误：protected_method 是protected
    
    return 0;
}
