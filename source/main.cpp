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
	ofstream file;

	string Target = "Hello, World!"; 

	vector<Mouse> population;
	
	for(int i = 0; i < pop_size; i++){
		Mouse Subject(Target, 0);
		population.push_back(Subject);
	}

	file.open("fitness_m5_s1.txt");

	sort(population.begin(), population.end(), CompareFitness);
	
	//for (int i = 0; i < 1; i++)
		//cout << population[i].getName() << "\t" << population[i].getFitness() << "\t" << population[i].getGeneration() << endl ;
	
	file << population[0].getFitness() << endl;
	

	vector<Mouse> child_population; 

	int q = 0;
	
	while(population[0].getFitness() != 0 && population[0].getGeneration() < 1000){
	child_population.clear();
	child_population = breed(population, Target, pop_size);
	population.clear();
	population = child_population;

	sort(population.begin(), population.end(), CompareFitness);

	cout << population[0].getName() << "\t" << population[0].getFitness() << "\t" << population[0].getGeneration() << endl;
	file << population[0].getFitness() << endl;
	}

	file.close();

	//int c;
	//cin >> c;

}