#ifndef OTTER_HPP
#define OTTER_HPP

#include "Animal.hpp"
#include "Food.hpp"
// cut out declarations/implementations as they are defined in base class
class Otter : public Animal {
public:
	Otter();

	// Overridden  so we can return AT_OTTER
	virtual AnimalType type() const;
};

#endif /* end of include guard: ELEPHANT_HPP */
