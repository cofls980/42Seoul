#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0;i < 100;i++)
		this->ideas[i] = "";
}

Brain::Brain(const Brain& ref)
{
	std::cout << "Brain copy assignment called" << std::endl;
	for (int i = 0;i < 100;i++)
		this->ideas[i] = ref.ideas[i];
}

Brain& Brain::operator=(const Brain& ref)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0;i < 100;i++)
		this->ideas[i] = ref.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	if (0 <= index && index < 100)
		this->ideas[index] = idea;
	else
		std::cout << "Wrong Index" << std::endl;
	/*std::string str = "In your main function, create and fill an array of Animal objects. \
	Half of it will be Dog objects and the other half will be Cat objects. At the end of your program execution, \
	loop over this array and delete every Animal. You must delete directly dogs and cats as Animals. \
	The appropriate destructors must be called in the expected order. \
	Don’t forget to check for memory leaks. A copy of a Dog or a Cat mustn’t be shallow. \
	Thus, you have to test that your copies are deep copies! Implement and turn in more tests than the ones given above.";
	std::stringstream ss(str);
	for (int i = 0;i < 100;i++)
	{
		ss >> this->ideas[i];
	}*/
}

std::string Brain::getIdea(int index) const
{
	if (0 <= index && index < 100)
		return this->ideas[index];
	std::cout << "Wrong Index" << std::endl;
	return "";
}