#include <iostream>
#include <limits>

int main(){
		
	// Create numeric_limits for type unsigned int 
	std::numeric_limits<unsigned int> limit;

	// Output the limits using std::cout
	std::cout << "unsigned int Range: " 
			<< limit.min() << "~" << limit.max() << std::endl;
	// Output the size using std::cout
	std::cout << "Size of unsigned int: " << sizeof(unsigned int) << std::endl;
	
	/* 
		Try to replace int with other data types (short, int, char, long, double, ...)
		Compare the different limits and size
	*/

	return 0;
}