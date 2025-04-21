#include <WordReader.h>
#include <arrayLists.h>
#include <iostream>
#include <linkedList.h>
#include <ostream>


int main(int argc, char**)
{
	
	ssuds::LinkedList<int> intList;

	for (int i = 0; i < 10; i++) {
		intList.append(i);
	}
	intList.output(std::cout);

	std::cout << "\n\n";

	for (int num : intList) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	intList.output(std::cout);

	std::cout << "\n";

	// geting size
	std::cout << "Size: " << intList.size() << std::endl << std::endl;


	//testing insert and prepent
	intList.insert(200, 5);
	intList.insert(250, intList.size());
	intList.prepend(500);
	intList.insert(2290, 0);

	intList.output(std::cout);
	std::cout << "\n";
	std::cout << "Size: " << intList.size() << std::endl << std::endl;

	std::cout << "intList: " << intList << std::endl;


	std::cout << "find 500:" << intList.find(500) << std::endl;
	std::cout << "find 9:" << *intList.find(9, intList.begin()) << std::endl;


}