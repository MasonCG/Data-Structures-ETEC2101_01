#include <Person.h> // why "" instead of <>
#include <iostream>

//<> is for standard libraries while "" is for local files
Person::Person()
{
	id = -1;
	first_name = "???";
	last_name = "???";
	hourly_rate = 0.0f;
	hours_worked = 0;

}

Person::Person(int starting_id, std::string start_fname, std::string start_lname)
{
	id = starting_id;
	first_name = start_fname;
	last_name = start_lname;
	hourly_rate = 0.0;
	hours_worked = 0;
}

Person::~Person()
{
	// we didn't allocate any resoures so no code is necessary
	std::cout << "Person " << first_name << " " << last_name << " has died.";
}

int Person::get_id()
{
	return id;
}

std::string Person::get_first_name()
{
	return first_name;
}

std::string Person::get_last_name()
{
	return last_name;
}

float Person::get_hourly_rate()
{
	return hourly_rate;
}

unsigned int Person::get_hours_worked()
{
	return hours_worked;
}

void Person::set_hours_worked(unsigned int new_hours)
{
	hours_worked = new_hours;
}

void Person::set_hourly_rate(float new_rate)
{
	hourly_rate = new_rate;
}


// We're providing teh body definition of the method we declared in our h file
float Person::calculate_wage()
{
	// In any (non-static) method, we have access to all attributes for this
	// instance. Our jon in this method is to tell the comiler how to 
	// calculate a wage using our attributes

	return hourly_rate * hours_worked;



}
