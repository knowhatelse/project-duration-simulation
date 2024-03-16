#pragma once

#ifndef OUTPUTRESPONSE_H
#endif // !OUTPUTRESPONSE_H

struct OutputResponse {
	int numberOfGeneratedTasks;
	int numberOfGeneratedMembers;

	float pertModelResult;

	float monteCarloFDResult = 0;
	float monteCarloRDResult = 0;

	bool savedTasksData = false;
	bool savedMembersData = false;
	bool savedAssignmentData = false;
	bool savedPertSimulationData = false;
	bool savedMCFDSimulationData = false;
	bool savedMCRDSimulationData = false;
};