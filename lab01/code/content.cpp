#include <iostream>
#include <string>

int main(){
	
	std::string default_attr = "\033[0m";       // Set attributes back to default
	std::string red_color    = "\033[31m";	    // Set the font color to red
	std::string blink_font   = "\033[5m";       // Make the text blink!
	std::string bold_font    = "\033[1m";       // Use bold font
	std::string green_bg     = "\033[42m";      // Set the background color to green

	std::cout << red_color << "Hello Red World!" << std::endl;
	std::cout << default_attr << "Hello Default World!" << std::endl;	
	std::cout << green_bg << blink_font << 
		"Hello Green Blinking World!" << std::endl;
	
	// You can try to keep outputting without going back to default attributes
	std::cout << "World, world never change!";

	// Nothing will be outputted explicitly if you only output the control sequence
	std::cout << default_attr << std::endl;
	std::cout << "Bye World!" << std::endl;

	return 0;
}