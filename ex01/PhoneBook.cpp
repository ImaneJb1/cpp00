#include "PhoneBook.hpp"
#include "string"

int	parse_phone_number(std::string input)
{
	int start = 0;
	int failure = 0;

	if(input[0] == '0')
	{
		if(input.length() != 10){failure = 1;}
	}
	else if(input[0] == '+')
	{
		start = 1;
		if(input.length() > 13 || input.length() < 8){failure = 1;}
	}
	else{failure = 1;}
	for(size_t i = start; i < input.size(); i++)
		if(!isdigit(input[i])){failure = 1;}
	if(failure == 1)
	{
		std::cout << "\033[31mFAILED: Please enter a valid phone number.\033[31m\n";
		return(0);
	}
	return(1);
}

int	PhoneBook::add_contact(int *index)
{
	std::string name;
	std::string phone_number;
	Contact contact;

	if(*index == 8)
		*index = 0;
	contact.set_first_name(get_input_loop("First name: "));
	contact.set_last_name(get_input_loop("Last name: "));
	contact.set_nickname(get_input_loop("Nickname: "));
	contact.set_phone_number(get_input_loop("Phone number: "));
	contact.set_dark_sec(get_input_loop("Darket secret: "));
	arr[*index] = contact;
	std::cout << "\033[32mContact added successfully!\033[32m" << '\n';
	return(1);
}

int	PhoneBook::display_contacts(void)
{
	int index = 0;
	
	std::cout << "\033[36m|  Index  |First Name| Last Name| Nickname |\033[0m\n";
	std::cout << "\033[36m----------+----------+----------+----------+\033[0m\n";
	while(index < 8)
	{
		if (!arr[index].get_first_name().empty())
		{
			arr[index].set_first_name(input_length(arr[index].get_first_name()));
			arr[index].set_last_name(input_length(arr[index].get_last_name()));
			arr[index].set_nickname(input_length(arr[index].get_nickname()));
			std::cout << "\033[36m|\033[0m" << std::setw(9) << index << "\033[36m|\033[0m";
			std::cout << std::setw(10) << arr[index].get_first_name() << "\033[36m|\033[0m";
			std::cout << std::setw(10)<< arr[index].get_last_name() << "\033[36m|\033[0m";
			std::cout << std::setw(10) << arr[index].get_nickname() << "\033[36m|\033[0m\n";
			std::cout << "\033[36m----------+----------+----------+----------+\033[0m\n";
		}
		index++;
	}
	return(1);
}

int	parse_index(int i)
{
	return(i <= 8 && i >= 0);
}

int main()
{
	PhoneBook phonebook;
	std::string input;
	int index = 0;
	
	while(1)
	{
		std::cout << "\033[33mPlease enter one of the commands : ADD, SEARCH, EXIT\033[0m\n";
		std::cout << "PhoneBook>> ";
		getline(std::cin, input);
		
		if(input == "ADD")
		{
			if(!phonebook.add_contact(&index))
				continue;
			index++;
		}
		else if(input == "SEARCH")
		{
			if (index > 0)
				phonebook.display_contacts();
			else
			{
				std::cout << "\033[31mNo data found\033[31m\n";			
				continue;
			}
			std::cout << "\033[32mTo exit the search bar press [ENTER].\033[32m\n";
			std::string str;
			int i;
			std::cout << "\033[37mEnter a number:\033[37m ";
			getline(std::cin, str);
			if(parse_input(str) == -1)
				str = loop_index(str);
			if(parse_input(str) == 0)
				continue;
			const char *new_str = str.c_str();
			i = atoi(new_str);
			if(!parse_index(i))
			{
				std::cout << "\033[31mData not found. Please enter a valid index.\033[31m\n";
				continue;
			}
			if (!phonebook.display_contact_by_index(i))
				continue;
		}
		else if(input == "EXIT")
			break;
		else
			std::cout <<"\033[31mCommand not found\033[31\n";
	}
	return 0;
}
