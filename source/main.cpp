#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

#include "../header/Mouse.h"
#include "../header/Functions.h"

using namespace std;

void main(){
	
	int pop_size = 10;
	srand((unsigned)time(0)); //init rng
	//ofstream file;
	
	string Target = "Now, I am become Death, the destroyer of worlds."; 

	vector<Mouse> population;
	
	for(int i = 0; i < pop_size; i++){
		Mouse Subject(Target, 0);
		population.push_back(Subject);
	}

	//file.open("length.txt");

	sort(population.begin(), population.end(), CompareFitness);
	
	cout << population[0].getName() << "\t" << population[0].getFitness() << "\t" << population[0].getGeneration() << endl ;
	
	//file << population[0].getName().length() << endl;
	

	vector<Mouse> child_population; 

	int q = 0;
	
	while(population[0].getFitness() != 0 && population[0].getGeneration() < 10000){
	child_population.clear();
	child_population = breed(population, Target, pop_size);
	population.clear();
	population = child_population;

	sort(population.begin(), population.end(), CompareFitness);

	cout << population[0].getName() << "\t" << population[0].getFitness() << "\t" << population[0].getGeneration() << endl;
	//file << population[0].getName().length() << endl;
	}

	//file.close();

	int c;
	cin >> c;
}