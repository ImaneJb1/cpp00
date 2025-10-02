#include "PhoneBook.hpp"

void	PhoneBook::add_contact(int index)
{
	std::string name;
	std::string phone_number;

	if(index == 8)
		index = 0;

	std::cout << "First name: ";
	std::cin >> name;
	arr[index].set_first_name(name);

	std::cout << "Last name: ";
	std::cin >> name;	
	arr[index].set_last_name(name);

	std::cout << "nickname: ";
	std::cin >> name;
	arr[index].set_nickname(name);

	std::cout << "Phone number: ";
	std::cin >> phone_number;
	//parse phone number
	arr[index].set_phone_number(name);

	std::cout << "Darket secret: ";
	std::cin >> name;
	arr[index].set_dark_sec(name);
}

void	PhoneBook::display_contact(int index)
{
	arr[index].set_first_name(input_length(arr[index].get_first_name()));
	arr[index].set_last_name(input_length(arr[index].get_last_name()));
	arr[index].set_nickname(input_length(arr[index].get_nickname()));
	
	std::cout << "\033[36m|  Index  |First Name| Last Name| Nickname |\033[0m\n";
	std::cout << "\033[36m----------+----------+----------+----------+\033[0m\n";
	std::cout << "\033[36m|\033[0m" << std::setw(9) << index << "\033[36m|\033[0m";
	std::cout << std::setw(10) << arr[index].get_first_name() << "\033[36m|\033[0m";
	std::cout << std::setw(10)<< arr[index].get_last_name() << "\033[36m|\033[0m";
	std::cout << std::setw(10) << arr[index].get_nickname() << "\033[36m|\033[0m\n";
	std::cout << "\033[36m----------+----------+----------+----------+\033[0m\n";
}

int main()
{
	PhoneBook phonebook;
	int index;
	std::string input;
	
	
	while(1)
	{
		std::cout << "\033[33menter one of the commands : ADD, SEARCH, EXIT\033[0m\n";
		std::cout << "PhoneBook>> ";
		getline(std::cin, input);
		if(input == "ADD")
		{
			phonebook.add_contact(index);
			index++;
		}
		else if(input == "SEARCH")
		{
			int i;
			std::cout << "Enter a number: ";
			std::cin >> i;
			//PARSE INDEX
			phonebook.display_contact(i);
		}
	}
	// PhoneBook.add_contact(arr, i);
	return 0;
}

