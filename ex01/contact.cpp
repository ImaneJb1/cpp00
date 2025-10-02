#include "contact.hpp"

void Contact::set_first_name(std::string input)
{
	first_name = input;
}

void Contact::set_last_name(std::string input)
{
	last_name = input;
}

void Contact::set_nickname(std::string input)
{
	nickname = input;
}

void Contact::set_dark_sec(std::string input)
{
	dark_sec = input;
}

void Contact::set_phone_number(std::string input)
{
	phone_number = input;
}

// geters


std::string Contact::get_first_name(void)
{
	return(first_name);
}

std::string Contact::get_last_name(void)
{
	return(last_name);
}

std::string Contact::get_nickname(void)
{
	return(nickname);
}

std::string Contact::get_dark_sec(void)
{
	return(dark_sec);
}

std::string Contact::get_phone_number(void)
{
	return(phone_number);
}


