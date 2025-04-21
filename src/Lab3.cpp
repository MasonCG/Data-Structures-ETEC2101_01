// Lab 3

#include <arrayLists.h>
#include <Person.h>
#include <ostream>
#include <iostream>
#include <string>


int main(int argc, char**)
{

	ssuds::ArrayList<int> intList;
	ssuds::ArrayList<int>::ArrayListIterator it = intList.begin();
	
	
	intList.append(45);
	intList.append(47);
	intList.append(43);
	intList.append(52);
	intList.append(72);
	intList.append(48);
	intList.append(32);


	std::cout << std::endl << "=== Array output & << operator ===" << std::endl;
	std::cout << std::endl;
	std::cout << "output(): \t";
	intList.output(std::cout); // [45, 47, 43, 52, 72, 48, 32]
	std::cout << std::endl; // ^^^
	std::cout << "<<: \t" << intList;
	std::cout << std::endl;
	std::cout << std::endl << "=== Array output & << operator ===" << std::endl;



	std::cout << std::endl << "=== for each loop ===" << std::endl;
	std::cout << std::endl;

	for (int integer :  intList) {
		std::cout << integer << "\n";
	}
	
	std::cout << std::endl << "=== for each loop ===" << std::endl;



	std::cout << std::endl << "=== iterator++ & ++iterator & + ===" << std::endl;
	std::cout << std::endl;

	std::cout << "it: " << *it << std::endl; // 45
	std::cout << "it + 2: " << *(it + 2) << std::endl; // 43
	std::cout << "++it: " << *(++it) << std::endl; //52
	std::cout <<  "it: " << *it; // 43
	std::cout << std::endl;

	std::cout << std::endl << "=== iterator++ & ++iterator & + ===" << std::endl;



	std::cout << std::endl << "=== [] operator ===" << std::endl;
	std::cout << std::endl;

	std::cout << "intList[0]: " << intList[0]; // 45
	std::cout << std::endl;
	std::cout << "intList[0]: " << intList[5]; // 48
	std::cout << std::endl;

	std::cout << std::endl << "=== [] operator ===" << std::endl;



	std::cout << std::endl << "=== Iterator Copy Constructor() ===" << std::endl;
	std::cout << std::endl;

	ssuds::ArrayList<int>::ArrayListIterator newIt(it);
	std::cout << "newIterator Svalue : " << *newIt << "\n"; // 43
	newIt + 2;
	std::cout << "newIt: " << *newIt << std::endl; // 72
	std::cout << "oldIt: " << *it << std::endl; // 43

	std::cout << std::endl << "=== Iterator Copy Constructor() ===" << std::endl;

	std::cout << std::endl << "=== ArrayList Copy Constructor() ===" << std::endl;
	std::cout << std::endl;


	std::cout << std::endl << "=== ArrayList Copy Constructor() ===" << std::endl;






	return 0;
}
