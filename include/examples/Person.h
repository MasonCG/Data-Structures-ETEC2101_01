// the #pragma once is a short-hand for the infndef
// the purpose of both is to prevent the compiler from ever seeting teh declaration
// of this class twice (which would case and error)





#ifndef _Person_H_
#define _Person_H_


#include <string>

namespace example {


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

		//constructor
		Person();

		Person(int starting_id, std::string start_fname, std::string start_lname);

		// Dectructor (called when an instance is about to be destroyed)
		~Person();


		int get_id();
		std::string get_first_name();
		std::string get_last_name();
		float get_hourly_rate();
		unsigned int get_hours_worked();

		//settter methods
		void set_hourly_rate(float new_rate);
		void set_hours_worked(unsigned int new_hours);

		float calculate_wage();



	};


}






#endif // !_Person_H_
