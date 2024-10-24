# Compiler settings - Can change to clang++ if required
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Build target executable:
TARGET = main

# Object files:
OBJS = main.o Person.o

# Rule to link the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the main program
main.o: main.cpp Person.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile the Person class
Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c Person.cpp

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: clean