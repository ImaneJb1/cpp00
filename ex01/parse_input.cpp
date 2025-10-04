#include "PhoneBook.hpp"
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

std::string	get_input_loop(std::string output)
{
	std::string input;
	while(1)
	{
		std::cout << "\033[37m" << output << "\033[37m";
		getline(std::cin, input);
		if(input.empty())
			std::cout << "\033[31mThis box can't be empty.\033[31m\n";
		else if(output == "Phone number: " && !parse_phone_number(input))
			continue;
		else
			break;
	}
	return(input);
}

int	PhoneBook::display_contact_by_index(int index)
{
	if(arr[index].get_first_name().empty()|| arr[index].get_last_name().empty()
		|| arr[index].get_nickname().empty())
	{
		std::cout << "\033[31mNo data found.\033[31m\n";
		return(0);
	}
	std::cout << "\033[32mFirst name:\033[32m ";
	std::cout << "\033[37m" << arr[index].get_first_name() << "\033[37m" << "\n";
	std::cout << "\033[32mLast name:\033[32m ";
	std::cout << "\033[37m" << arr[index].get_last_name() << "\033[37m" << "\n";
	std::cout << "\033[32mNickname:\033[32m ";
	std::cout << "\033[37m" << arr[index].get_nickname() << "\033[37m" << "\n";
	std::cout << "\033[32mPhone number:\033[32m ";
	std::cout << "\033[37m" << arr[index].get_phone_number() << "\033[37m" << "\n";
	std::cout << "\033[32mDarkest secret:\033[32m ";
	std::cout << "\033[37m" << arr[index].get_dark_sec() << "\033[37m" << "\n";
	return(1);
}
// void	parse_index()
int	parse_input(std::string input)
{
	if(input.empty())
		return(0);
	for(int i = 0; input[i]; i++)
	{
		if(!std::isdigit(input[i]))
		{
			std::cout << "\033[31mInvalid index\033[31m\n";
			return(-1);
		}
	}
	return(1);
}

std::string	loop_index(std::string input)
{
	while(1)
	{
		std::cout << "\033[37mEnter a number:\033[37m ";
		getline(std::cin, input);
		if(parse_input(input) >= 0)
			break;
	}
	return(input);
}
