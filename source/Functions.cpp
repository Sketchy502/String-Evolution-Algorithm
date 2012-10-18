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

		std::string new_name;
		int test_length;


		Mouse parent_one = parents[0];
		Mouse parent_two = parents[rand()%5+1];
		Mouse longest("a",0);

		int child_length = (parent_one.getName().length() + parent_two.getName().length())/2;

		if (rand()%5 == 0) child_length += random(-1,1);

		if(parent_one.getName().length() < parent_two.getName().length()){
			test_length = parent_one.getName().length();
			longest = parent_two;
		}else {
			test_length = parent_two.getName().length();
			longest = parent_one;
		}

		std::string parent_name;

		for (int i = 0; i < child_length; i++)
		{
			if(i < test_length){
				if(rand()%2 == 0)
					parent_name = parent_one.getName();
				else
					parent_name = parent_two.getName();
			new_name += parent_name[i];
			}else if(i < longest.getName().length() && i >= test_length){
					new_name += longest.getName()[i];
			}else{
				new_name += random('0','z');
			}
		}

		Mouse child(new_name, target, parents[0].getGeneration() + 1);

		child.setName(new_name);
	    child.mutate(1,1);

		child.calc_fitness(target);

		children.push_back(child);
	}

	return children;
}