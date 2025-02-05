#include "person_database.h"
#include <iostream>
#include <fstream>

// person_database.cpp

example::PersonDatabase::PersonDatabase(std::string fname)
{
	// initialize attributes
	my_array = nullptr;
	int my_array_size = 0;
	filename = fname;

	// open file
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		
		// type in an exception =========
		std::cout << "Error: File '" << filename << "' is not opening.\n\n";
		return;
	}

	int temp_id;
	int temp_hours;
	float temp_hourly_rate;
	std::string temp_fname;
	std::string temp_lname;

	while (!fin.eof()) {
		// get lines worth of data

		fin >> temp_fname;
		if (fin.eof()) {
			break;
		}
		fin >> temp_lname;	
		fin >> temp_id;
		fin >> temp_hourly_rate;
		fin >> temp_hours;

		example::Person temp_person(temp_id, temp_fname, temp_lname);
		temp_person.set_hourly_rate(temp_hourly_rate);
		temp_person.set_hours_worked(temp_hours);

		//use our add person to do the hard work
		add_person(temp_person);


	}
	fin.close();
}

void example::PersonDatabase::add_person(example::Person p)
{
	//case 1: nothing in the array
	// code: make an array of size 1 and put p in the only spot


	if (!my_array) {
		my_array = new Person[my_array_space];
		my_array[0] = p;
		my_array_size = 1;
	}

	// case 2: array is already there (slide 16)
	// code: make an array of my_array_size + 1, copy data from existing array to that new array, Free
	else {
			
		my_array_size++;
		int final_index = my_array_size - 1;

		if (my_array_size > my_array_space) {
			my_array_space *= 2;
		}


		Person* temp_array = new Person[my_array_space];
		
		for (int i = 0; i < final_index; i++) {
			temp_array[i] = my_array[i];
			
		}

		temp_array[final_index] = p;

		delete[] my_array;
		my_array = temp_array;
	}

	
}

void example::PersonDatabase::remove_person(int id)
{


	Person* temp_array = new Person[my_array_space];
	int temp_index = 0;

	unsigned int array_length = my_array_size;

	for (int i = 0; i < array_length; i++) {

		if (my_array[i].get_id() == id) {
			my_array_size--;
			continue;
		}

		//int temp_id = my_array[i].get_id();


	
		temp_array[temp_index] = my_array[i];
		temp_index++;

	}


	delete[] my_array;
	my_array = temp_array;
}

std::string example::PersonDatabase::to_string()
{

	std::string my_string;

	my_string += "\n================================================================\n";
	my_string += "Name\t\t\tID\tHourly Rate\tHours Worked\n";
	my_string += "==============\t\t====\t===========\t============\n";


	for (int i = 0; i < my_array_size; i++) {
		my_string += my_array[i].get_first_name() + "\t";
		my_string += my_array[i].get_last_name() + "\t\t";
		my_string += std::to_string(my_array[i].get_id()) + "\t";
		my_string += std::to_string(my_array[i].get_hourly_rate()) + "\t";
		my_string += std::to_string(my_array[i].get_hours_worked()) + "\n";

	}

	my_string += "================================================================\n";


	return my_string;
}

int example::PersonDatabase::get_num_people()
{
	return my_array_size;
}

example::PersonDatabase::~PersonDatabase() {

	std::ofstream fout(filename);

	for (int i = 0; i < my_array_size; i++) {
	
		fout << my_array[i].get_first_name() << " ";
		fout << my_array[i].get_last_name() << " ";
		fout << my_array[i].get_id() << " ";
		fout << my_array[i].get_hourly_rate() << " ";
		fout << my_array[i].get_hours_worked() << "\n";

	}

	fout.close();

}


