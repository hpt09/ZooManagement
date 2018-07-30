#include "Elephant.hpp"

using namespace std;
// commented out as they are defined in base class
Elephant::Elephant() {
	foodIntake = 8400;
	reset = 8400;
	foodA = "banana";
	foodB = "watermelon";
	foodC = "hay";
}

Animal::AnimalType Elephant::type() const {
	return AT_ELEPHANT;
}
