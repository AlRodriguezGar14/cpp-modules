#include "Harl.hpp"

int main(int argc, char **argv) {

	Harl h;

	if (argc != 2) {
		std::cout << "Usage: ./ex06 <complain level>" << std::endl;
		return 1;
	}
	ComplainLevel level = getLevel(toLower(argv[1]));
	switch (level) {
		case DEBUG:
			h.complain(DEBUG);
			/*fall through*/
		case INFO:
			h.complain(INFO);
			/*fall through*/
		case WARNING:
			h.complain(WARNING);
			/*fall through*/
		case ERROR:
			h.complain(ERROR);
			break;
		case NONE:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

	return 0;
}
