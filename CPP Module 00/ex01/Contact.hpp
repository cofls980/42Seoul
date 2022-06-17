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
	Contact(void);
	void add(void);
	void display(void);
	void display_specific_contact(void);
	//~Contact(void);//소멸자
};

#endif