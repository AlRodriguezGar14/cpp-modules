#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int idx = 1; idx != argc; ++idx)
	{
		for (int jdx = 0; argv[idx][jdx]; ++jdx)
			std::cout << static_cast<char>(std::toupper(argv[idx][jdx]));
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
