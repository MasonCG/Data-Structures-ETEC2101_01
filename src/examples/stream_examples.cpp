// examples of using cin/cout, also file input/output, stringstrea
#include <iostream>
#include <string>

int main(int argc, char** argv)
{

	int x = 42;
	float y;
	std::string s;
	
	std::cout << "x = " << x << "\n"; //CHEVRON goes to the left (<<) -- output
	
	std::cout << "Enter an integer value of x: ";
	std::cin >> x;
	if (std::cin.fail()) {
		std::cout << "Invlaid integer. Setting x to -1\n";
		x = -1;
		// note, tehe \n is still in teh cin buffer. we don't want it there
		std::cin.clear();
		// note2: clearing the error has to come first
		std::cin.ignore(1, '\n');


	}

	std::cout << "Enter a float value for y: ";
	std::cin >> y;
	
	//std::cout << "Enter a string value for s: ";
	//std::cin >> s;

	//if we want any type of text
	// note4: since we have some input already, theres likely a newline still in the buffer.
	std::cin.ignore(1000, '\n');
	std::cout << "Enter a string value for s: ";
	std::getline(std::cin, s);

	std::cout << "You entered\n\tx= " << x << "\n\ty= " << y << "\n\ts= " << s << "\n";

	return 0;
}