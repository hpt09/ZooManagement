#include "Monkey.hpp"

using namespace std;
// cut out declarations/implementations as they are defined in base class
Monkey::Monkey() {
	foodIntake = 800;
	reset = 800;
	foodA = "banana";
	foodB = "watermelon";
	foodC = "mealworms";
}

Animal::AnimalType Monkey::type() const {
	return AT_MONKEY;
}

