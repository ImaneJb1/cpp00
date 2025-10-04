#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <iomanip>
#include "string"
class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string dark_sec;
		std::string phone_number;
	public:
		void set_first_name(std::string input);	
		void set_last_name(std::string input);
		void set_dark_sec(std::string input);
		void set_nickname(std::string input);
		void set_phone_number(std::string input);

		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nickname(void);
		std::string get_dark_sec(void);
		std::string get_phone_number(void);
};
std::string	loop_index(std::string input);
std::string	input_length(std::string input);
#endif