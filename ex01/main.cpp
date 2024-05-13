#include "Contact.hpp"
#include "PhoneBook.hpp"

bool	is_valid_prompt(std::string prompt)
{
	if (prompt == "ADD" || prompt == "SEARCH" || prompt == "EXIT")
		return true;
	std::cout << "Invalid command" << std::endl;
	return false;
}

enum Command {
	ADD,
	SEARCH,
	EXIT,
	INVALID
};

Command get_command(const std::string& prompt) {
	if (prompt == "ADD") return ADD;
	if (prompt == "SEARCH") return SEARCH;
	if (prompt == "EXIT") return EXIT;
	return INVALID;
}

int	main()
{
	PhoneBook	pn;
	Command		cmd;

	std::string prompt;
	int running = 1;

	while (running)
	{
		prompt = get_input("\nChoose one of these commands:\n> ADD, SEARCH, EXIT <\n");
		while (!is_valid_prompt(prompt))
			prompt = get_input("\nChoose one of these commands:\n> ADD, SEARCH, EXIT <\n");
		cmd = get_command(prompt);
		switch (cmd) {
			case EXIT:
				running = 0;
				break ;
			case SEARCH:
				pn.search();
				break ;
			case ADD:
				pn.add();
				break ;
			default:
				break ;
		}
	}
}
