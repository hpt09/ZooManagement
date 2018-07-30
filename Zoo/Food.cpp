#include "Food.hpp"
#include <string>

using namespace std;
//intialises all the variables 
Food::Food(const string& new_name, double new_cost, unsigned int new_energy) {
	name = new_name;
	cost = new_cost;
	energy = new_energy;
	quantity = 0;
}

string Food::getName() const {
	return name;
}

double Food::getCost() const {
	return cost;
}

unsigned int Food::getQuantity() const {
	return quantity;
}

unsigned int Food::getEnergy() const {
	return energy;
}

unsigned int Food::consume(unsigned int count) {
	/* returns the quantity of food actually gonna be consumed 
	if the number provided to be consumed is less than the quantity then 
	thats the number we will consume and quantity will decrease by that amount
	or else the number will be equal or greater and hence we will consume all of the quantity we have */
	if (count < quantity) {
		quantity -= count;
		return count;
	}
	else {
		unsigned int consumed = quantity;
		quantity = 0;
		return consumed;
	}
}

void Food::purchase(unsigned int quantity) {
	// Decreases the quantity in food scope by the quantity in purchase scope
	this->quantity = this->quantity + quantity;
}
