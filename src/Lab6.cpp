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


	std::cout << "find 500: " << intList.find(500) << std::endl;
	std::cout << "find 9: " << *intList.find(9, intList.begin()) << std::endl;


	std::cout << "================ REMOVE TESTING ===================\n\n";
	std::cout << "+++ removing with index +++\n";
	intList.remove(0);
	std::cout << "remove at 0: " << intList << std::endl;
	intList.remove(intList.size()-1);
	std::cout << "remove at " << intList.size() - 1 << ": " << intList << std::endl;
	intList.remove(5);
	std::cout << "remove at 5: " << intList << std::endl;
	intList.remove(5);
	std::cout << "remove at 5: " << intList << std::endl << std::endl;;

	std::cout << "+++ removing with iterator +++\n";
	ssuds::LinkedList<int>::LinkedListIterator it = intList.begin();
	intList.remove(it);
	it = ++intList.begin();
	std::cout << "remove intList.begin(): " << intList << std::endl;
	intList.remove(it);
	std::cout << "remove ++intList.begin(): " << intList << std::endl;


	std::cout << "\n+++ removing by value +++\n";
	ssuds::LinkedList<float> floatList;

	floatList.append(4.5f);
	floatList.append(4.50f);
	floatList.append(5.48f);
	floatList.append(5.48f);
	floatList.append(4.5f);
	floatList.append(2.5f);

	unsigned int removed = 0;

	std::cout << floatList << std::endl;
	removed = floatList.remove_all(2.5f);
	std::cout << "removed (" << removed << "), 2.5: " << floatList << std::endl;

	removed = floatList.remove_all(4.5f);
	std::cout << "removed (" << removed << "), 4.5: " << floatList << std::endl << std::endl;

	std::cout << "================ at() TESTING ===================\n\n";

	for (float i = 4.5f; i < 6.7f; i += 0.25f) {
		floatList.append(i);
	}

	std::cout << "new_list: " << floatList << std::endl;

	std::cout << "floatList[4]: " << floatList[4] << ", floatList.at(4): " << floatList.at(4) << std::endl;


}