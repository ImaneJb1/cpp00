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
		if(input.length() != 13){failure = 1;}
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

int	PhoneBook::add_contact(int index)
{
	std::string name;
	std::string phone_number;
	Contact contact;

	if(index == 8)
		index = 0;

	std::cout << "First name: ";
	getline(std::cin, name);
	if(name.empty())
	{std::cout << "\033[31mThis box can't be empty\033[31m\n";
		return(0);}
	contact.set_first_name(name);

	std::cout << "Last name: ";
	getline(std::cin, name);
	if(name.empty())
	{std::cout << "\033[31mThis box can't be empty\033[31m\n";
		return(0);}
	contact.set_last_name(name);

	std::cout << "nickname: ";
	getline(std::cin, name);
	if(name.empty())
	{std::cout << "\033[31mThis box can't be empty\033[31m\n";
		return(0);}
	contact.set_nickname(name);

	std::cout << "Phone number: ";
	getline(std::cin, name);
	if(!parse_phone_number(phone_number)){return(0);}
	contact.set_phone_number(name);

	std::cout << "Darket secret: ";
	getline(std::cin, name);
	if(name.empty())
	{std::cout << "\033[31mThis box can't be empty\033[31m\n";
		return(0);}
	contact.set_dark_sec(name);
	arr[index] = contact;
	return(1);
}

int	PhoneBook::display_contact(int index)
{
	arr[index].set_first_name(input_length(arr[index].get_first_name()));
	arr[index].set_last_name(input_length(arr[index].get_last_name()));
	arr[index].set_nickname(input_length(arr[index].get_nickname()));
	if(arr[index].get_first_name().empty()|| arr[index].get_last_name().empty()
		|| arr[index].get_nickname().empty())
	{
		std::cout << "\033[31mNo data found.\033[31m\n";
		return(0);
	}
	
	std::cout << "\033[36m|  Index  |First Name| Last Name| Nickname |\033[0m\n";
	std::cout << "\033[36m----------+----------+----------+----------+\033[0m\n";
	std::cout << "\033[36m|\033[0m" << std::setw(9) << index << "\033[36m|\033[0m";
	std::cout << std::setw(10) << arr[index].get_first_name() << "\033[36m|\033[0m";
	std::cout << std::setw(10)<< arr[index].get_last_name() << "\033[36m|\033[0m";
	std::cout << std::setw(10) << arr[index].get_nickname() << "\033[36m|\033[0m\n";
	std::cout << "\033[36m----------+----------+----------+----------+\033[0m\n";
	return(1);
}

int	parse_index(int i)
{
	return(i <= 8 && i >= 0);
}

int main()
{
	PhoneBook phonebook;
	int index = 0;
	std::string input;
	
	while(1)
	{
		std::cout << "\033[33mPlease enter one of the commands : ADD, SEARCH, EXIT\033[0m\n";
		std::cout << "PhoneBook>> ";
		getline(std::cin, input);
		
		if(input == "ADD")
		{
			// if(phonebook.add_contact(index) == 0)
			// {
			// 	std::cout << "\033[31mError: empty line.\033[31m\n";
			// 	continue;
			// }
			if(!phonebook.add_contact(index))
				continue;
			index++;
		}
		else if(input == "SEARCH")
		{
			std::string str;
			int i;
			std::cout << "Enter a number: ";
			getline(std::cin, str);
			const char *new_str = str.c_str();
			i = atoi(new_str);
			if(!parse_index(i))
			{
				std::cout << "\033[31mData not found. Please enter a valid index.\033[31m\n";
				continue;
			}
			if (!phonebook.display_contact(i))
				continue;
		}
		else if(input == "EXIT")
			break;
		else
			std::cout <<"\033[31mCommand not found\033[31\n";
	}
	return 0;
}
