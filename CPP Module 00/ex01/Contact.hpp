#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>

class Contact {
private :
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public :
	Contact();
	void add();
	void display();
	void display_specific_contact();
	//~Contact();
	//Contact(std::string fn, std::string ln, std::string nn, std::string ph, std::string ds);
};

#endif