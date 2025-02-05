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

	int x2;
	float y2;
	std::string s2;


	while (true) {

		if (fin.eof()) {
			break;
		}

		std::cout << "hello\n";

	}

	while (true)
	{
		// Note: the end of file (eof) function doesn't become true
		// until we try to read past the end of the file.

		if (fin.eof())
			break;

		fin >> x2;
		fin.ignore(1000, ':');
		fin >> y2;
		fin.ignore(1000, ':');
		//fin >> s2;
		std::getline(fin, s2);

		std::cout << "Values read in:\n\tx2=" << x2 << "\n\ty2=" << y2 << "\n\ts2='" << s2 << "'\n";
	}
#endif

	return 0;
}