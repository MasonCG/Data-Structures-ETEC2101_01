// the #pragma once is a short-hand for the infndef
// the purpose of both is to prevent the compiler from ever seeting teh declaration
// of this class twice (which would case and error)





#ifndef _Person_H_
#define _Person_H_


#include <string>

class Person
{
	// attributes

	// by default everything is private:

	private:
		int id;
		std::string first_name;
		std::string last_name;
		float hourly_rate;
		unsigned int hours_worked;

		//Method
	public:
		float calculate_wage();
};









#endif // !_Person_H_
