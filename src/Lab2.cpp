// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <string>
#include <arrayLists.h>
#include <Person.h>


int main()
{
	// The basic test program (for floats)
	ssuds::ArrayList<float> float_list;

	std::cout << "\nAppend() & size() & capacity:\n\n"; // test1 (basics):
	float_list.append(2.1f);
	float_list.append(5.5f);
	float_list.prepend(3.6f);
	std::cout << "\tsize= " <<  float_list.size() << std::endl; // size=3
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=4
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [3.6, 2.1, 5.5]
	std::cout << "\n===============================\n\n";

	std::cout << "reserve(): \n\n"; // test1 (more):
	float_list.reserve(100);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=3
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=100
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [3.6, 2.1, 5.5]
	std::cout << "\n===============================\n\n";

	std::cout << "remove(0) & output():\n\n"; // test1 (more):
	float_list.remove(0);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=2
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=50
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.1, 5.5]
	std::cout << "\n===============================\n\n";

	std::cout << "remove(1): \n\n"; // test1 (more):
	float_list.remove(1);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=1
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=25
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.1]
	std::cout << "\n===============================\n\n";

	std::cout << "remove(1): \n\n"; // test1 (more):
	float_list.reserve(4);
	float_list.append(5.5f);
	float_list.append(2.4f);
	float_list.remove(2);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=1
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=25
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.1]
	std::cout << "\n===============================\n\n";

	std::cout << "insert(0, 2): \n\n"; // test1 (more):
	float_list.insert(2.5f, 0);
	float_list.insert(8.9f, 1);
	float_list.insert(3.2f, 2);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=4
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=25
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 8.9, 3.2, 2.1]
	std::cout << "\n===============================\n\n";

	std::cout << "at(): \n\n"; // test1 (more):
	std::cout << "\tvalue= " << float_list.at(3) << std::endl; // value=2.1
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 8.9, 3.2, 2.1]
	std::cout << "\n===============================\n\n";

	std::cout << "find(): \n\n"; // test1 (more):
	std::cout << "\index= " << float_list.find(8.9) << std::endl; // index=1
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 8.9, 3.2, 2.1]
	std::cout << "\n===============================\n\n";

	std::cout << "remove_all(): \n\n"; // test1 (more):
	float_list.append(2.1f);
	float_list.append(5.5f);
	float_list.append(2.1f);
	float_list.append(5.5f);
	float_list.append(8.9f);
	float_list.append(8.9f);
	std::cout << "\size= " << float_list.size() << std::endl; // size=10
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 8.9, 3.2, 2.1, 2.1, 5.5, 2.1, 5.5, 8.9, 8.9]
	std::cout << "\n";
	std::cout << "\tremoved= " << float_list.remove_all(8.9f) << std::endl; // removed=3
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=7
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 3.2, 2.1, 2.1, 5.5, 2.1, 5.5]
	std::cout << "\n===============================\n\n";





	// Person array list testing
	ssuds::ArrayList<example::Person> personList(10);

	std::cout << "\nAppend() & size() & capacity:\n\n"; // test1 (basics):
	float_list.append(2.1f);
	float_list.append(5.5f);
	float_list.prepend(3.6f);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=3
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=4
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [3.6, 2.1, 5.5]
	std::cout << "\n===============================\n\n";

	std::cout << "reserve(): \n\n"; // test1 (more):
	float_list.reserve(100);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=3
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=100
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [3.6, 2.1, 5.5]
	std::cout << "\n===============================\n\n";

	std::cout << "remove(0) & output():\n\n"; // test1 (more):
	float_list.remove(0);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=2
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=50
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.1, 5.5]
	std::cout << "\n===============================\n\n";

	std::cout << "remove(1): \n\n"; // test1 (more):
	float_list.remove(1);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=1
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=25
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.1]
	std::cout << "\n===============================\n\n";

	std::cout << "insert(0, 2): \n\n"; // test1 (more):
	float_list.insert(2.5f, 0);
	float_list.insert(8.9f, 1);
	float_list.insert(3.2f, 2);
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=4
	std::cout << "\tcapacity= " << float_list.capacity() << std::endl; // capacity=25
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 8.9, 3.2, 2.1]
	std::cout << "\n===============================\n\n";

	std::cout << "at(): \n\n"; // test1 (more):
	std::cout << "\tvalue= " << float_list.at(3) << std::endl; // value=2.1
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 8.9, 3.2, 2.1]
	std::cout << "\n===============================\n\n";

	std::cout << "find(): \n\n"; // test1 (more):
	std::cout << "\index= " << float_list.find(8.9) << std::endl; // index=1
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 8.9, 3.2, 2.1]
	std::cout << "\n===============================\n\n";

	std::cout << "remove_all(): \n\n"; // test1 (more):
	float_list.append(2.1f);
	float_list.append(5.5f);
	float_list.append(2.1f);
	float_list.append(5.5f);
	float_list.append(8.9f);
	float_list.append(8.9f);
	std::cout << "\size= " << float_list.size() << std::endl; // size=10
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 8.9, 3.2, 2.1, 2.1, 5.5, 2.1, 5.5, 8.9, 8.9]
	std::cout << "\n";
	std::cout << "\tremoved= " << float_list.remove_all(8.9f) << std::endl; // removed=3
	std::cout << "\tsize= " << float_list.size() << std::endl; // size=7
	std::cout << "\toutput= ";
	float_list.output(std::cout); // output= [2.5, 3.2, 2.1, 2.1, 5.5, 2.1, 5.5]
	std::cout << "\n===============================\n\n";
}

