# Mac C++ Enviroment Setup Tutorial
Mac ususally has already installed the clang compiler and the make tool. So you can 
create a test cpp file directly
```shell
mkdir test
cd test
touch main.cpp
```
Write the following code in the file:
```cpp
#include <iostream>

int main() {
  std::cout << "HKUST(GZ) 2024" << std::endl;
  return 0;
}
```
Compile and run
```shell
clang++ main.cpp -o main
./main
```
If you see the output "HKUST(GZ) 2024", you have successfully set up the C++ environment in Mac.

### Addtional Content
If you want to use makefile, here is an example for you to refer:
```makefile
src = $(wildcard ./*.c)  
obj = $(patsubst %.c, %.o, $(src))  
#obj = $(src:%.c=%.o)  
target = app  
CC = clang++  

$(target): $(obj)  
    $(CC) $(obj) -o $(target)  

%.o: %.c  
    $(CC) -c $< -o $@  
    
.PHONY: clean  
clean:  
    rm -rf $(obj) $(target)
```
If you want to configure VS Code, you can refer [link](https://code.visualstudio.com/docs/cpp/config-clang-mac).