#ifndef MOUSE_H
#define MOUSE_H

#include <string>

class Mouse{
	private:
		std::string name;
		int fit_val;
		int generation;
	public:
		Mouse(std::string, int);
		void calc_fitness(std::string);
		void mutate(int, int);
		void setName(std::string);
		std::string getName();
		int getFitness();
		int nameLength();
		void incGeneration();
		int getGeneration();

};

#endif