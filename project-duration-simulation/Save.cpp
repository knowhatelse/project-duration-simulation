#include "Save.h"

bool Save::tasksToCSV(vector<Task>& tasks) {
	ofstream file;
	file.open("Tasks.csv", ios_base::app);

	if (file.is_open() == false) {
		return false;
	}

	file << "TaskID" << "," 
		<< "O_Time" << "," 
		<< "P_Time" << "," 
		<< "ML_Time" << "," 
		<< "RequestChangeProbability" << "," 
		<< "DelayTime" << endl;

	for (int i = 0; i < tasks.size(); i++) {
		file << tasks[i].id << "," 
			<< tasks[i].optimisticTime << "," 
			<< tasks[i].pessimisticTime << "," 
			<< tasks[i].mostLikelyTime << "," 
			<< tasks[i].requestChangeProbabilityValue << "," 
			<< tasks[i].delayTime << endl;
	}

	file.close();
	return true;
}
	 
bool Save::membersToCSV(vector<Member>& members) {
	ofstream file;
	file.open("Members.csv", ios_base::app);

	if (file.is_open() == false) {
		return false;
	}

	file << "MemberID" << "," << "Experience" << endl;

	for (int i = 0; i < members.size(); i++) {
		file << members[i].id << "," << members[i].experience << endl;
	}

	file.close();
	return true;
}
	 
bool Save::taskAssignmentToCSV(vector<Task>& tasks) {
	ofstream file;
	file.open("AssignedMembers.csv", ios_base::app);

	if (file.is_open() == false) {
		return true;
	}

	file << "TaskID" << "," << "MemberID" << "," << "MembersExperience" << endl;

	for (int i = 0; i < tasks.size(); i++) {
		file << tasks[i].id << "," << tasks[i].member.id << "," << tasks[i].member.experience << endl;
	}

	file.close();
	return true;
}
	 
bool Save::pertSimulationResultsToCSV(vector<Task>& tasks) {
	ofstream file;
	file.open("PertSimulationResults.csv", ios_base::app);

	if (file.is_open() == false) {
		return false;
	}

	file << "TaskID" << "," << "EstimatedTime" << endl;

	for (int i = 0; i < tasks.size(); i++) {
		file << tasks[i].id << "," << tasks[i].estimatedTime << endl;
	}

	file.close();
	return true;
}
	 
bool Save::MCFDSimulationResultsToCSV(vector<float>& results) {
	ofstream file;
	file.open("MonteCatloFDSimulationResults.csv", ios_base::app);

	if (file.is_open() == false) {
		return false;
	}

	file << "IterationNumber" << "," << "Result" << endl;

	for (int i = 0; i < results.size(); i++) {
		file << i << "," << results[i] << endl;
	}

	file.close();
	return true;
}
	 
bool Save::MCRDSimulationResultsToCSV(vector<float>& results) {
	ofstream file;
	file.open("MonteCatloRDSimulationResults.csv", ios_base::app);

	if (file.is_open() == false) {
		return false;
	}

	file << "IterationNumber" << "," << "Result" << endl;

	for (int i = 0; i < results.size(); i++) {
		file << i << "," << results[i] << endl;
	}

	file.close();
	return true;
}