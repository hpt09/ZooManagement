#ifndef MONKEY_HPP
#define MONKEY_HPP

#include "Animal.hpp"
#include "Food.hpp"
// cut out declarations/implementations as they are defined in base class
class Monkey : public Animal {
public:
	Monkey();

	// Overridden so we can return AT_MONKEY
	virtual AnimalType type() const;
};

#endif /* end of include guard: MONKEY_HPP */
