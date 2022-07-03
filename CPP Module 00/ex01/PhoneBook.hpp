#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {
private :
	int		count;
	int		oldest;
	Contact users[8];

public :
	PhoneBook(void);
	void add(Contact user);
	int display(void);
	int search(int index);
	void lost_contacts(void);
};

#endif