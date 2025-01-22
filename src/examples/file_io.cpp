#include <iostream>
#include <string>
#include <fstream>		// Access to fstream, ofstream, ifstream


# define MAIN_MODE 1 // 0=output, 1=input
#define FNAME "../../media/test.txt"


int main(int argc, char** argv) {

#if MAIN_MODE == 0

	//std::ofstream fout;
	// note: working directory is set the the debug folder in bin
	//fout.open("test.txt");

	int x = 42;
	float y = 3.1f;
	std::string s = "Hello World!";

	std::ofstream fout("../../media/test.txt");

	fout << x << ":" << y << ":" << s << "\n";
	x++;
	y++;
	s += "XXX";
	fout << x << ":" << y << ":" << s << "\n";

#else
	// Alternate main program (for output)
	std::ifstream fin(FNAME);

	if (!fin.is_open()) {
		std::cout << "Error opening file' "<< FNAME <<" '\n";
		return 1;
	}
	while (!fin.eof()) {
		int x2;
		float y2;
		std::string s2;

		fin >> x2;
		fin.ignore(1000, ':');
		fin >> y2;
		fin.ignore(1000, ':');
		std::getline(fin, s2);
		fin >> s2;

		std::cout << x2 << y2 << s2;
	}
#endif

	return 0;
}