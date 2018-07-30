#ifndef LION_HPP
#define LION_HPP

#include "Animal.hpp"
#include "Food.hpp"
// cut out declarations/implementations as they are defined in base class
class Lion : public Animal {
public:
	Lion();

	// Overridden  so we can return AT_LION
	virtual AnimalType type() const;
};

#endif /* end of include guard: LION_HPP */
