#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
private :
	int		count;
	int		oldest;
	Contact users[8];

public :
	PhoneBook();
	void add(Contact user);
	int display();
	int search(int index);
	//~PhoneBook();
};

#endif