#pragma once

#include <Person.h>

namespace example {
	/// <summary>
	/// takes person data from given file, adds them to an array. as persons are added and deleted from the array the database will change
	/// when an instance of PersonDatabase is destroyed it will write all of its current persons to given file.
	/// </summary>
	class PersonDatabase {
		private:
			/// <summary>
			///	pointer to begginning of array
			/// </summary>
			Person* my_array;
			/// <summary>
			/// contains the amount of persons in the array
			/// </summary>
			unsigned int my_array_size;
			/// <summary>
			/// contains the amount of person size spaces in the array
			/// </summary>
			unsigned int my_array_space = 5;
			/// <summary>
			/// name of txt file where person data is stored
			/// </summary>
			std::string filename;

			
		public:
			/// <summary>
			/// creates array and uploads persons from given file to the array. 
			/// </summary>
			/// <param name="fname">name of the file that holds person data</param>
			PersonDatabase(std::string fname);
			/// <summary>
			///	gets the number of person in the database
			/// </summary>
			/// <returns>the number of persons in the database</returns>
			int get_num_people();
			/// <summary>
			/// removes a person from the database
			/// </summary>
			/// <param name="id">id of a Person instance</param>
			void remove_person(int id);
			/// <summary>
			/// creates a string of the current database in a special format.
			/// </summary>
			/// <returns> a string of information about the persons in the database</returns>
			std::string to_string();
			/// <summary>
			/// frees the array and writes persons in database to given file
			/// </summary>
			~PersonDatabase();
			/// <summary>
			/// adds a person to the database
			/// </summary>
			/// <param name="p">Person instance</param>
			void add_person(Person p);

	};

}