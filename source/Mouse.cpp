#include "../header/Mouse.h"
#include "../header/Functions.h"


//constructor for mouse with random name
Mouse::Mouse(std::string target, int gen){

	int length = random(1, 2*target.length());
	for(int j = 0; j < length; j++)
			name += random('0', 'z');
	Mouse::calc_fitness(target); 

	generation = gen;
}

//constructor for mouse with pre-determined name
Mouse::Mouse(std::string new_name, std::string target, int gen){

	name = new_name;
	Mouse::calc_fitness(target); 

	generation = gen;
}

//calculate the fitness based on interger distaces of chars, costs defined in Mouse.h
void Mouse::calc_fitness(std::string target){
	fit_val = 0;
	int test_length;
	if(name.length() > target.length()) test_length = target.length();
	else test_length = name.length();

	for(int i = 0; i < test_length; i++){
		fit_val += (name[i] - target[i] )*(name[i] - target[i])*CHAR_COST;
	}

	fit_val += ((name.length() - target.length())*(name.length() - target.length())) * LENGTH_COST;
}

//randomly mutate a given number of characters in the name by a given size
void Mouse::mutate(int number, int size){
	if (number > name.length()) number = name.length();
	for (int i = 0; i < number; i++){
	int pos = random(0, name.length());
	name[pos] += random(-size,size);
	}
}


// get/set values
void Mouse::setName(std::string new_name){
	name = new_name;
}

int Mouse::nameLength(){
	return name.length();
}

int Mouse::getFitness(){
	return fit_val;
}

std::string Mouse::getName(){
	return name;
}

void Mouse::incGeneration(){
	generation++;
}

int Mouse::getGeneration(){
	return generation;
}
