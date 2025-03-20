#include "WordReader.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>

namespace ssuds{
	
	WordReader::WordReader() {
		fname = "../../media/american-words.txt";
		fin.open(fname, std::ios::binary);

		if (!fin.is_open()) {

			throw std::runtime_error("file at: " + fname + " could not be located");
			return;
		}

	}

	WordReader::WordReader(std::string filename) {
		fname = filename;
		std::ifstream fin(fname);

		if (!fin.is_open()) {
			throw std::runtime_error("file at: " + fname + " could not be located");
			return;
		}

	}


	std::string WordReader::getWord()
	{

		fin.seekg(0, std::ios::end);
		int flength = fin.tellg();
		int rByte = std::rand() % flength -1;

		fin.seekg(rByte, std::ios::beg);

		char c = fin.peek();
		
		while (c != 10) {
			fin.seekg(-1, std::ios::cur);
			c = fin.peek();
		}

		fin.seekg(1, std::ios::cur);

		std::string word;
		std::getline(fin, word);

		return word;

	}

	WordReader::~WordReader() {
		fin.close();
	}
}
