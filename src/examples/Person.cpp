#include "Person.h" // why "" instead of <>

//<> is for standard libraries while "" is for local files


// We're providing teh body definition of the method we declared in our h file
float Person::calculate_wage()
{
	// In any (non-static) method, we have access to all attributes for this
	// instance. Our jon in this method is to tell the comiler how to 
	// calculate a wage using our attributes

	return hourly_rate * hours_worked;



}
