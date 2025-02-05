// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include <Person.h>
#include <person_database.h>

#define TEST_FILE "../../media/persondb.txt"

int main()
{
	// in this constructor you'll read in the contents of the 
	// text file into an array of Person Objects. DO NOT use any
	// container types (std::vector, std::list, etc.)

	example::PersonDatabase PD("../../media/persondb.txt");


	int choice;


	while (true) {

		std::cout << "\n====== DataBase ======\n";
		std::cout << "Enter 1 to add person\n";
		std::cout << "Enter 2 to remove person\n";
		std::cout << "Enter 3 to print database\n";
		std::cout << "Enter 4 to quit\n\n";
		std::cout << "Answer: ";
		std::cin >> choice;



		if (choice == 1) {
			std::string fname;
			std::cout << "\nPlease enter a first name: ";
			std::cin >> fname;

			std::string lname;
			std::cout << "Please enter a last name: ";
			std::cin >> lname;

			int id;
			std::cout << "Please enter an ID: ";
			std::cin >> id;

			float hourly_rate;
			std::cout << "Please enter an hourly rate: ";
			std::cin >> hourly_rate;

			int hours_worked;
			std::cout << "Please enter an hours worked: ";
			std::cin >> hours_worked;

			example::Person temp_person(id, fname, lname);
			temp_person.set_hourly_rate(hourly_rate);
			temp_person.set_hours_worked(hours_worked);

			PD.add_person(temp_person);

			std::cout << "\nYou have successfully added " << fname << "!\n";

		}

		else if (choice == 2) {
			int id;
			std::cout << "\nPlease enter person ID: ";
			std::cin >> id;

			PD.remove_person(id);


			std::cout << "\nYou have successfully removed person " << id << "!\n";

		}

		else if (choice == 3) {
			std::cout << PD.to_string();
		}

		else if (choice == 4) {
			break;
		}

		else {
			std::cout << "\nYou did not enter a valid choice. Please try again.\n";
		}



	}

	std::cout << PD.to_string();


}
