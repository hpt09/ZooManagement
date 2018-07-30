#ifndef ELEPHANT_HPP
#define ELEPHANT_HPP

#include "Animal.hpp"
#include "Food.hpp"
// Cut out declarations/implementations as they are defined in base class
class Elephant : public Animal {
public:
	Elephant();

	// Overridden  so we can return AT_ELEPHANT
	virtual AnimalType type() const;

};

#endif /* end of include guard: ELEPHANT_HPP */
