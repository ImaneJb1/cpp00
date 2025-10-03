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
		int	display_contact(int index);
};

#endif