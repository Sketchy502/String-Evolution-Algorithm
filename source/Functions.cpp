#include "../header/Functions.h"

int random(int lower, int upper){
	if(lower < 0) upper++;

	int range = upper - lower;
	return (rand() % range)+lower;
}

bool CompareFitness(Mouse A, Mouse B){
	return (A.getFitness() < B.getFitness());
}

std::vector<Mouse> breed(std::vector<Mouse> parents, std::string target, int pop_size){
	std::vector<Mouse> children;
	
	for(int j = 0; j < pop_size; j++)
	{
		Mouse child(target, parents[0].getGeneration() + 1);
		std::string new_name = target;

		for (int i = 0; i < child.nameLength(); i++)
		{
			int parent = rand()%2;
			std::string parent_name = parents[parent].getName();
			new_name[i] = parent_name[i];
		}

		child.setName(new_name);
	    child.mutate(5,1);

		child.calc_fitness(target);

		children.push_back(child);
	}

	return children;
}