#ifndef MOUSE_H
#define MOUSE_H

#include <string>

//Length cost is such that the correct length is more benefitial than wrong characters
#define CHAR_COST 1
#define LENGTH_COST 300

class Mouse{
	private:
		std::string name;
		int fit_val;
		int generation;
	public:
		Mouse(std::string, int);
		Mouse(std::string , std::string , int);
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