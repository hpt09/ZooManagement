#include "Animal.hpp"

Animal::~Animal() {
}

//returns invalid here but is defined in subclasses for their own type
Animal::AnimalType Animal::type() const {
	return AT_INVALID;
}

//foodIntake is returned for hunger level
unsigned int Animal::hungerLevel() const {
	return foodIntake;
}

//foodIntake is set to reset value which was the original foodIntake value
void Animal::resetToHungry() {
	foodIntake = reset;
}

//food's getName is implemented to get the name of the food and is compared with strings 
bool Animal::likesFood(const Food& food) const {
	if (food.getName() == foodA || food.getName() == foodB || food.getName() == foodC) {
		return true;
	}
	else {
		return false;
	}
}

// hungerLevel is divided by energy level of food which gives us amount of feedNeeded 
// since its integer division, we check if its fully divisible then we have the correct quantity of food needed
// or if theres any remainder 1 more quantity of food is needed. We consumed feedNeeded and store the actual consumed food
// if consumed food was equal to feedNeeded then foodIntake is now zero which is our HungerLevel or less food might be consumed
// which in case quantity of consumed food's energy is gotten and subtracted from hunger level.
unsigned int Animal::feed(Food& food) {
	unsigned int feed = food.getQuantity();
	unsigned int feedNeeded = hungerLevel() / food.getEnergy();
	unsigned int consumed;
	if(likesFood(food)){
	if (hungerLevel() % food.getEnergy() == 0) {
		consumed = food.consume(feedNeeded);
	}
	else {
		feedNeeded++;
		consumed = food.consume(feedNeeded);
	}
	if (consumed == feedNeeded) {
		foodIntake = 0;
	}
	else {
		foodIntake = foodIntake - (consumed * food.getEnergy());
	}
	return (feed - food.getQuantity());
	}
}
