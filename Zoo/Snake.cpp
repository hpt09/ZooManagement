#include "Snake.hpp"

using namespace std;
// cut out declarations/implementations as they are defined in base class
Snake::Snake() {
	foodIntake = 250;
	reset = 250;
	foodA = "mouse";
	foodB = "mouse";
	foodC = "egg";
}

Animal::AnimalType Snake::type() const {
	// TODO: Implement
	return AT_SNAKE;
}
