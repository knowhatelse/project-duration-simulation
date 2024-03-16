#include "Simulation.h"

Simulation::Simulation(InputResponse& userInput) {
	_userInput = userInput;
	monteCarloFDResults = vector<float>();
	monteCarloRDResults = vector<float>();
}

float& Simulation::pertModelSimulation(vector<Task>& tasks) const {
	float totalTime = 0.0f;
	float maxTaskTime = 0.0f;

	for (int i = 0; i < tasks.size(); i++) {
		float te = (static_cast<float>(tasks[i].optimisticTime) + (4 * tasks[i].mostLikelyTime) + tasks[i].pessimisticTime) / 6;

		if (_userInput.requestChangeProbabilityType == 0) {
			int coefficient = (1 + (rand() % 100)) / 100;
			if (coefficient <= tasks[i].requestChangeProbabilityValue) {
				te += tasks[i].delayTime;
			}
		}
		else {
			float additionalTime = tasks[i].requestChangeProbabilityValue * te;
			te += additionalTime;
		}
		
		te *= tasks[i].member.experience;
		tasks[i].estimatedTime = te / 24;
		totalTime += te;

		if (te > maxTaskTime) {
			maxTaskTime += te - maxTaskTime;
		}

	}
	
	float result = ceil(((totalTime + maxTaskTime) / 2) / 24);
	return result;
}

float& Simulation::monteCarloFDSimulation(vector<Task>& tasks) {
	float total = 0;

	for (int i = 0; i < _userInput.monteCarloIterations; i++) {
		float simulationResults = pertModelSimulation(tasks);
		monteCarloFDResults.push_back(simulationResults);
		total += simulationResults;
	}

	float result = ceil(total / _userInput.monteCarloIterations);
	return result;
}

float& Simulation::monteCarloRDSimulation() {
	float totalNumberOfDays = 0;

	for (int i = 0; i < _userInput.monteCarloIterations; i++) {
		Generator generator = Generator(_userInput);
		vector<Task> tasks = generator.generateTasks();
		vector<Member> members = generator.generateMembers();

		Assign::membersToTasks(members, tasks);

		float simulationResult = pertModelSimulation(tasks);
		monteCarloRDResults.push_back(simulationResult);
		totalNumberOfDays += simulationResult;
	}

	float result = ceil(totalNumberOfDays / _userInput.monteCarloIterations);
	return result;
}