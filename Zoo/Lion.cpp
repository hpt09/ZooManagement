#include "Lion.hpp"

#include "Food.hpp"

using namespace std;
// cut out declarations/implementations as they are defined in base class
Lion::Lion() {
	foodIntake = 2200;
	reset = 2200;
	foodA = "steak";
	foodB = "mouse";
	foodC = "fish";
}

Animal::AnimalType Lion::type() const {
	return AT_LION;
}
