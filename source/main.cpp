#include <iostream>
#include <cmath>
#include <algorithm>

#include "../header/Mouse.h"
#include "../header/Functions.h"

using namespace std;

int main(){
	
	int pop_size = 10; // Set Population size
	srand((unsigned)time(0)); // init RNG
	
	string Target;

	//Set target string
	cout << "Please enter a word or two: ";
	getline(cin, Target);

	vector<Mouse> population;
	
	//Generate initial population
	for(int i = 0; i < pop_size; i++){
		Mouse Subject(Target, 0);
		population.push_back(Subject);
	}

	//Sort population based on fitness
	sort(population.begin(), population.end(), CompareFitness);
	
	//Print best
	cout << endl << endl << population[0].getName() << "\t" << population[0].getFitness() << "\t" << population[0].getGeneration() << endl ;	

	vector<Mouse> child_population; 
	
	//Breed and generate new populations whilst fitness is greater than zero or less than 10,000 generations
	while(population[0].getFitness() != 0 && population[0].getGeneration() < 10000){
	child_population.clear();
	child_population = breed(population, Target, pop_size);
	population.clear();
	population = child_population;

	//sort population
	sort(population.begin(), population.end(), CompareFitness);

	//prints info
	system("CLS");
	cout << "Please enter a word or two: " << Target << endl << endl;
	cout << "Current Word" << endl;
	cout << population[0].getName() << endl << endl;
	cout << "Fitness" << endl;
	cout << population[0].getFitness() << endl << endl;
	cout << "Current Generation" << endl;
	cout << population[0].getGeneration() << endl << endl;
	}

	system("pause");

	return 0;
}