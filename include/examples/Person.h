// the #pragma once is a short-hand for the infndef
// the purpose of both is to prevent the compiler from ever seeting teh declaration
// of this class twice (which would case and error)





#ifndef _Person_H_
#define _Person_H_
#include <string>


/// <summary>
/// namespace for examples and not official lab stuff
/// </summary>
namespace example {

	/// <summary>
	/// Person object holds all person data.
	/// </summary>
	class Person
	{
		// attributes

		// by default everything is private:

	private:
		/// <summary>
		/// unique ID for each Person
		/// </summary>
		int id;
		/// <summary>
		/// First name of Person
		/// </summary>
		std::string first_name;
		/// <summary>
		/// Last name of Person
		/// </summary>
		std::string last_name;
		/// <summary>
		/// Person's hourly rate
		/// </summary>
		float hourly_rate;
		/// <summary>
		/// Person's hours_worked in a week
		/// </summary>
		unsigned int hours_worked;

		//Method
	public:

		/// <summary>
		/// creates a Person with a unique ID and no other attributes
		/// </summary>
		Person();
		/// <summary>
		/// Creating a person object when given an ID, first name and last name
		/// </summary>
		/// <param name="starting_id">Person's unique ID</param>
		/// <param name="start_fname">Person's first name</param>
		/// <param name="start_lname">Person's last name</param>
		Person(int starting_id, std::string start_fname, std::string start_lname);

		/// <summary>
		/// does nothing
		/// </summary>
		~Person();

		/// <summary>
		/// Grabs Person's unique ID
		/// </summary>
		/// <returns>integer</returns>
		int get_id();
		/// <summary>
		/// Grabs Person's first name
		/// </summary>
		/// <returns>string</returns>
		std::string get_first_name();
		/// <summary>
		/// Grabs Person's last name
		/// </summary>
		/// <returns>string</returns>
		std::string get_last_name();
		/// <summary>
		/// Grabs Person's hourly rate
		/// </summary>
		/// <returns>float</returns>
		float get_hourly_rate();
		/// <summary>
		/// Grabs Person's hours worked in a week
		/// </summary>
		/// <returns>unsigned integer</returns>
		unsigned int get_hours_worked();

		/// <summary>
		/// Sets the Person's hourly rate
		/// </summary>
		/// <param name="new_rate">New hourly rate as a float</param>
		void set_hourly_rate(float new_rate);
		/// <summary>
		/// Sets the Person's hours worked in the current week
		/// </summary>
		/// <param name="new_hours">new hours worked as an unsigned int</param>
		void set_hours_worked(unsigned int new_hours);
		/// <summary>
		/// takes ostream and puts in Person's ID
		/// </summary>
		/// <param name="os">ostream desired to be directed towards</param>
		/// <param name="p">Person object</param>
		/// <returns>ostream</returns>
		friend std::ostream& operator<< (std::ostream& os, const Person& p);

		/// <summary>
		/// compares Person's unique ID's 
		/// </summary>
		/// <param name="p">Person Object</param>
		/// <returns>Boolean</returns>
		bool operator== (const Person& p);
		/// <summary>
		/// Calculates Person's wage: hours*rate
		/// </summary>
		/// <returns>Person's wage that week as a float</returns>
		float calculate_wage();



	};


}






#endif // !_Person_H_
