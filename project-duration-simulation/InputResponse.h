#pragma once

#ifndef INPUTRESPONSE_H
#endif // !INPUTRESPONSE_H

#include <string>

using namespace std;

struct InputResponse {
	//Task related data.
	int tasksFrom;
	int tasksTo;
	int tasksTimeFrom;
	int tasksTimeTo;

	int requestChangeProbabilityType;
	int requestChangeProbabilityValue;

	//Members related data
	int membersFrom;
	int membersTo;
	int memberExperienceFrom;
	int memberExperienceTo;

	//Monte Carlo simulation related data.
	int monteCarloOption;
	int monteCarloIterations;

	//Saving date to CSV related data.
	int saveData;
};