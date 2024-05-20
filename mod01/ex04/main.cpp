#include <iostream>
#include <fstream>
#include <string>

bool validateInput(int argc) {
	return (argc == 4);
}

void    parseInput(int argc, char** argv, std::string &filename, std::string& s1, std::string& s2, std::string& outFile) {

	if (!validateInput(argc))
		throw std::invalid_argument("Invalid number of arguments");
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	outFile = filename + ".replace";
}

void openFiles(std::fstream& fd, std::fstream& outFd, std::string& filename, std::string& outFile) {

	fd.open(filename.c_str(), std::fstream::in);
	if (!fd.good())
		throw std::runtime_error("Can't open the file");

	outFd.open(outFile.c_str(), std::fstream::out);
	if (!outFd.good())
		throw std::runtime_error("Can't create the new file");
}

void    replaceAndWrite(std::fstream& fd, std::fstream& outFd, std::string& s1, std::string& s2) {

	std::string line;

	while (std::getline(fd, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) // npos is the return of find if nothing is found (-1)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outFd << line << '\n';
	}
}

int main(int argc, char **argv)
{
	std::fstream fd;
	std::fstream outFd;
	std::string filename, s1, s2, outFile;

	try {
		parseInput(argc, argv, filename, s1, s2, outFile);
		openFiles(fd, outFd, filename, outFile);
	} catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return 1;
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	replaceAndWrite(fd, outFd, s1, s2);
	fd.close();
	outFd.close();

	return 0;
}