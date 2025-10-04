#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"
#include "stdlib.h"
class PhoneBook
{
	private:
		Contact arr[8];
	public:
		int	add_contact(int index);
		int	display_contacts(void);
		int display_contact_by_index(int index);
};
std::string	get_input_loop(std::string output);
int	parse_phone_number(std::string input);
int	parse_input(std::string input);
#endif