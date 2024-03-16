#include "Assign.h"

void Assign::membersToTasks(vector<Member>& members, vector<Task>& tasks) {
	for (int i = 0; i < tasks.size(); i++) {
		int randomMemberId = rand() % members.size();
		tasks[i].member = members[randomMemberId];
	}
}