#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"

class PhoneBook
{
	private:
		Contact arr[8];
	public:
		int	add_contact(int index);
		void	display_contact(int index);
};

#endif