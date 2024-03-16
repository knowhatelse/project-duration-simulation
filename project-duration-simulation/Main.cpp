#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Input.h"
#include "Output.h"
#include "Generator.h"
#include "Assign.h"
#include "Simulation.h"
#include "Save.h"

int main() {
	srand(time(0));

	InputResponse userInput = Input::userInput();
	OutputResponse programResponse{};

	Generator generator = Generator(userInput);
	vector<Task> tasks = generator.generateTasks();
	vector<Member> members = generator.generateMembers();

	programResponse.numberOfGeneratedTasks = tasks.size();
	programResponse.numberOfGeneratedMembers = members.size();

	Assign::membersToTasks(members, tasks);

	Simulation simulations = Simulation(userInput);
	programResponse.pertModelResult = simulations.pertModelSimulation(tasks);

	switch (userInput.monteCarloOption) {
		case 1: programResponse.monteCarloFDResult = simulations.monteCarloFDSimulation(tasks); break;
		case 2: programResponse.monteCarloRDResult = simulations.monteCarloRDSimulation(); break;
		case 3: {
			programResponse.monteCarloFDResult = simulations.monteCarloFDSimulation(tasks);
			programResponse.monteCarloRDResult = simulations.monteCarloRDSimulation();
		}
	}

	if (userInput.saveData == 1) {
		programResponse.savedTasksData = Save::tasksToCSV(tasks);
		programResponse.savedMembersData = Save::membersToCSV(members);
		programResponse.savedAssignmentData = Save::taskAssignmentToCSV(tasks);
		programResponse.savedPertSimulationData = Save::pertSimulationResultsToCSV(tasks);
		programResponse.savedMCFDSimulationData = Save::MCFDSimulationResultsToCSV(simulations.monteCarloFDResults);
		programResponse.savedMCRDSimulationData = Save::MCRDSimulationResultsToCSV(simulations.monteCarloRDResults);
	}

	Output::programOutput(programResponse);
	
	system("pause>0");
	return 0;
}