#include "Otter.hpp"

using namespace std;
// cut out declarations/implementations as they are defined in base class
Otter::Otter() {
	foodIntake = 750;
	reset = 750;
	foodA = "fish";
	foodB = "mouse";
	foodC = "mouse";
}

Animal::AnimalType Otter::type() const {
	return AT_OTTER;
}
