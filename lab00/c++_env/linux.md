# Linux C++ Environment Setup Tutorial
Install gcc and gdb. If you use Ubuntu or Debian, you can use the following command:
```shell
sudo apt-get update
sudo apt-get install build-essential gdb
```
Create a test file
```shell
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
g++ main.cpp -o main
./main
```
If you see the output "HKUST(GZ) 2024", you have successfully set up the C++ environment in Linux.
### Addtional Content
If you want to use makefile, here is an example for you:
```makefile
src = $(wildcard ./*.c)  
obj = $(patsubst %.c, %.o, $(src))  
#obj = $(src:%.c=%.o)  
target = app  
CC = g++  

$(target): $(obj)  
    $(CC) $(obj) -o $(target)  

%.o: %.c  
    $(CC) -c $< -o $@  
    
.PHONY: clean  
clean:  
    rm -rf $(obj) $(target)
```
If you want to configure VS Code, you can refer the tutorial [link](https://code.visualstudio.com/docs/cpp/config-linux)