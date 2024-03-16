#pragma once

#ifndef SIMULATION_H
#endif // !SIMULATION_H

#include <vector>
#include "Task.h"
#include "Generator.h"
#include "Assign.h"
#include "InputResponse.h"

using namespace std;

class Simulation {
	InputResponse _userInput;

public:
	vector<float> monteCarloFDResults;
	vector<float> monteCarloRDResults;

	Simulation(InputResponse& userInput);

	float& pertModelSimulation(vector<Task>& tasks) const;
	float& monteCarloFDSimulation(vector<Task>& tasks);
	float& monteCarloRDSimulation();
};
