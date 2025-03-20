#pragma once

#include <string>
#include <fstream>


namespace ssuds {
	class WordReader{
	private:
		std::string fname;
		std::ifstream fin;
		
	public:
		WordReader();
		WordReader(std::string filename);
		std::string getWord();
		~WordReader();

	};

}