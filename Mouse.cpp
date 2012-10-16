#include "Mouse.h"
#include "Functions.h"

Mouse::Mouse(std::string target, int gen){
	name = target;
	for(int j = 0; j < name.length(); j++)
			name[j] = random('0', 'z');
	Mouse::calc_fitness(target); 

	generation = gen;
}

void Mouse::calc_fitness(std::string target){
	fit_val = 0;
	for(int i = 0; i < name.length(); i++){
		fit_val += (name[i] - target[i])*(name[i] - target[i]);
	}
}

void Mouse::mutate(int number, int size){
	if (number > name.length()) number = name.length();
	for (int i = 0; i < number; i++){
	int pos = random(0, name.length());
	name[pos] += random(-size,size);
	}
}

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
