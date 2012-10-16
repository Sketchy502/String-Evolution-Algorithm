#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>
#include <cstdlib>
#include <vector>

#include "Mouse.h"

int random(int, int);

bool CompareFitness(Mouse A, Mouse B);

std::vector<Mouse> breed(std::vector<Mouse>, std::string, int);

#endif