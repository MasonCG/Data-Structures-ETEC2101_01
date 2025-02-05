#pragma once

#include <Person.h>

namespace example {
	class PersonDatabase {
		private:

			Person* my_array;
			unsigned int my_array_size;
			unsigned int my_array_space = 5;
			std::string filename;

			// methods
		public:
			PersonDatabase(std::string fname);
			int get_num_people();
			void remove_person(int id);
			std::string to_string();
			~PersonDatabase();
			void add_person(Person p);

	};

}