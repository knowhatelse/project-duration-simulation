#pragma once

#ifndef SAVE_H
#endif // !SAVE_H

#include <vector>
#include <fstream>
#include "Task.h"

using namespace std;

class Save {
public:
	static bool tasksToCSV(vector<Task>& tasks);
	static bool membersToCSV(vector<Member>& members);
	static bool taskAssignmentToCSV(vector<Task>& tasks);
	static bool pertSimulationResultsToCSV(vector<Task>& tasks);
	static bool MCFDSimulationResultsToCSV(vector<float>& resultsHolder);
	static bool MCRDSimulationResultsToCSV(vector<float>& resultsHolder);
};