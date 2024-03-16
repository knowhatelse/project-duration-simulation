#include "Output.h"

string Output::_crt = "----------------------------------------------------------------------------------------------------";
string Output::_dot = "....................................................................................................";

void Output::programOutput(OutputResponse& outputResponse) {
	system("CLS");
	
	cout << _crt << endl;

	cout << "SIMULATION RESULTS" << endl;

	cout << _dot << endl;

	cout << "Number of generated members: " << outputResponse.numberOfGeneratedMembers << endl;
	cout << "Number of generated tasks: " << outputResponse.numberOfGeneratedTasks << endl;

	cout << _dot << endl;

	cout << "PERT Model simulation result: " << outputResponse.pertModelResult << endl;

	cout << _dot << endl;

	if (outputResponse.monteCarloFDResult != 0) {
		cout << "Monte Carlo (fixed data) simulation result: " << outputResponse.monteCarloFDResult << " days." << endl;
	}
	
	if (outputResponse.monteCarloRDResult != 0) {
		cout << "Monte Carlo (random data) simulation result: " << outputResponse.monteCarloRDResult << " days." << endl;
	}
	

	if (outputResponse.savedTasksData) {
		cout << _dot << endl;
		cout << "Tasks data has been saved to a CSV file..." << endl;
	}

	if (outputResponse.savedMembersData) {
		cout << "Members data has been saved to a CSV file..." << endl;
	}

	if (outputResponse.savedAssignmentData) {
		cout << "Assignment data has been saved to a CSV file..." << endl;
	}

	if (outputResponse.savedPertSimulationData) {
		cout << "PERT simulation data has been saved to a CSV file..." << endl;
	}

	if (outputResponse.savedMCFDSimulationData) {
		cout << "Monte Carlo - fixed data has been saved to a CSV file..." << endl;
	}

	if (outputResponse.savedMCRDSimulationData) {
		cout << "Monte Carlo - random data has been saved to a CSV file..." << endl;
	}

	cout << _crt << endl;
}