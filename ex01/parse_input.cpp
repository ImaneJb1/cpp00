#include "contact.hpp"
#include "cstring"

std::string	input_length(std::string input)
{
	int len = input.length();

	if(len > 10)
	{
		input[9] = '.';
		input = input.substr(0, 10);
	}
	return (input);
}

// void	parse_index()
