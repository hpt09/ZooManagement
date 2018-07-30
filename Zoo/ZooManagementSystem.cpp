#include "ZooManagementSystem.hpp"

#include <iostream>

using namespace std;

ZooManagementSystem::ZooManagementSystem(double initialBalance) {
	balance = initialBalance;
}

// running a loop to delete all animals in animalCollection
ZooManagementSystem::~ZooManagementSystem() {
	for (unsigned int i = 0; i < animalCollection.size(); i++) {
		delete animalCollection[i];
	}
	animalCollection.clear();

}

string ZooManagementSystem::author() {
	return "hsin612";
}

double ZooManagementSystem::getBalance() const {
	return balance;
}

double ZooManagementSystem::admitVisitors(unsigned int adults, unsigned int children) {
	/*Family passes can only have equal amount of adults and children. (2 each) We check which out of the two are lower
	  and see if it is divisible by 2 then we have that number of family passes. Admit fees will have number of family passes 
	  times cost of family pass 30. We need to see if if the smaller group were fully divisible by 2 so we use modulus to see if there was adult
	  remaining or if there were 0 and multiply it by cost of that group. We need to subract the amount of family passes times 2 from
	  the bigger group as thats how many would be covered by family pass and multiply that by cost of the bigger group.*/
	if (adults < children) {
		unsigned int familyPass = adults / 2;
		admitFees = (familyPass * 30 + 14 * (adults % 2) + (5 * (children - familyPass * 2)));
		balance += admitFees;
	}
	else {
		unsigned int familyPass = children / 2;
		admitFees = (familyPass * 30 + 5 * (children % 2) + (14 * (adults - familyPass * 2)));
		balance += admitFees;
	}

	return admitFees;
}

vector<Food> ZooManagementSystem::getFood() const {
	return foodCollection;
}

void ZooManagementSystem::addFood(const Food& new_food) {
	foodCollection.push_back(new_food);

}

bool ZooManagementSystem::purchaseFood(double& cost, unsigned int index, unsigned int quantity) {
	/*Check if the index provided is in the normal range. Use getCost for that food which has that index in foodCollection 
	  and multiply by the quantity we need to get and save that in cost variable. Check if our balance is higher than cost
	  and decrease the balance by cost and use purchase method of that food to increase quantity of food by the parameter provided*/
	if (index >= foodCollection.size() || index < 0) {
		cost = 0.0;
		return false;
	}
	cost = (foodCollection[index].getCost() * quantity);
	if (balance < cost) {
		return false;
	}
	else {
		balance -= cost;
		foodCollection[index].purchase(quantity);
		return true;
	}
}

vector<Animal*> ZooManagementSystem::getAnimals() const {
	return animalCollection;
}

bool ZooManagementSystem::addAnimal(Animal::AnimalType new_animal_type) {
	// Check individual animal types with the type provided and make a new animal on the heap and add it into the animal collection.
	if (new_animal_type == Animal::AT_INVALID) {
		return false;
	}
	else if (new_animal_type == Animal::AT_MONKEY) {
		Animal* new_animal = new Monkey();
		animalCollection.push_back(new_animal);
		return true;
	}
	else if (new_animal_type == Animal::AT_LION) {
		Animal* new_animal = new Lion();
		animalCollection.push_back(new_animal);
		return true;
	}
	else if (new_animal_type == Animal::AT_SNAKE) {
		Animal* new_animal = new Snake();
		animalCollection.push_back(new_animal);
		return true;
	}
	else if (new_animal_type == Animal::AT_OTTER) {
		Animal* new_animal = new Otter();
		animalCollection.push_back(new_animal);
		return true;
	}
	else if (new_animal_type == Animal::AT_ELEPHANT) {
		Animal* new_animal = new Elephant();
		animalCollection.push_back(new_animal);
		return true;
	}

}

ZooManagementSystem::FeedResult ZooManagementSystem::feedAnimal(unsigned int& quantity_eaten, unsigned int animal_index, unsigned int food_index) {
	/*Check if animal index and food index are in normal range. Check if animal likes the food by using the likesFood method
	  Feed the animal provided food by using feed method and store it in quantity eaten. Check if hunger level of that animal
	  is equal to 0 or not. Return appropriate types in each check.*/
	if (animal_index >= animalCollection.size() || animal_index < 0) {
		quantity_eaten = 0;
		return FR_INVALID_ANIMAL;
	}
	if (food_index >= foodCollection.size() || food_index < 0) {
		quantity_eaten = 0;
		return FR_INVALID_FOOD;
	}
	if (animalCollection[animal_index]->likesFood(foodCollection[food_index]) == false) {
		quantity_eaten = 0;
		return FR_INCOMPATIBLE;
	}
	quantity_eaten = animalCollection[animal_index]->feed(foodCollection[food_index]);
	if (animalCollection[animal_index]->hungerLevel() == 0) {
		return FR_SUCCESS;
	}
	else {
		return FR_EXHAUSTED;
	}


}

void ZooManagementSystem::resetAllAnimals() {
	// Go through a loop and use resetToHungry method on each animal
	for (unsigned int i = 0; i < animalCollection.size(); i++) {
		animalCollection[i]->resetToHungry();
	}
}

void ZooManagementSystem::feedAllAnimals() {
	/* I Run bubble sort on animalCollection and foodCollection sorting it by hunger level and quantity respectively.
	   So both the vectors would contain hungriest animal first and food with the most quantity first. 
	   I run a nested loop to go through every food for every animal and use feedAnimal in a while loop 
	   until Success is outputted or it goes through every index of foodCollection and then the next animal 	goes through the same process. Every loop, foodCollection goes through bubble sort so the quantity with 
	the most food always comes first*/

	for(int i = 0; i <animalCollection.size(); i++){	//make an array of pointers
	animalTemp.push_back(animalCollection[i]);
	}
	
	for (int i = 0; i < animalTemp.size(); i++)
	{
		for (int j = animalTemp.size() - 1; j > i; j--)
		{
			if (animalTemp[j]->hungerLevel() > animalTemp[j - 1]->hungerLevel())
			{
				animalRef = animalTemp[j - 1];
				animalTemp[j - 1] = animalTemp[j];
				animalTemp[j] = animalRef;
			}
		}
	}

	unsigned int eaten;	

	for(int i = 0; i <foodCollection.size(); i++){	//make an array of pointers
	foodRef = &foodCollection[i];
	foodTemp.push_back(foodRef);
	}

	for (int k = 0; k < animalTemp.size(); k++) {

		for (int i = 0; i < foodTemp.size(); i++)		//running the bubble sort in a loop so highest quantity of foods goes first
		{
			for (int j = foodTemp.size() - 1; j > i; j--)
			{
				if (foodTemp[j]->getQuantity() > foodTemp[j - 1]->getQuantity())
				{
					foodRef = foodTemp[j - 1];
					foodTemp[j - 1] = foodTemp[j];
					foodTemp[j] = foodRef;
				}
			}
		}													// bubble sort ends here
		
		for(int i=0; i<foodTemp.size(); i++){
		animalTemp[k]->feed(*foodTemp[i]);
			
		}
	

	}
}
