#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Animal.hpp"
#include "Food.hpp"
// cut out declarations/implementations as they are defined in base class
class Snake : public Animal {

public:
	Snake();

	// Overridden  so we can return AT_SNAKE
	virtual AnimalType type() const;
};

#endif /* end of include guard: SNAKE_HPP */
