#include "Generator.h"

Generator::Generator(InputResponse& userInput) {
	_userInput = userInput;
}

vector<Task> Generator::generateTasks() const {
	vector<Task> tasks;
	int idCounter = 1;

	for (int i = _userInput.tasksFrom; i <= _userInput.tasksTo; i++) {
		Task task{};
		int coefficient = _userInput.tasksTimeFrom + (rand() % ((_userInput.tasksTimeTo/2) - _userInput.tasksTimeFrom + 1));

		task.id = idCounter;
		task.optimisticTime = _userInput.tasksTimeFrom + (rand() % (_userInput.tasksTimeTo - _userInput.tasksTimeFrom + 1));
		task.pessimisticTime = task.optimisticTime + coefficient;
		task.mostLikelyTime = (task.optimisticTime + task.pessimisticTime) / 2;
		task.requestChangeProbabilityValue = ((rand() % _userInput.requestChangeProbabilityValue) + static_cast<float>(1)) / 100;
		task.delayTime = _userInput.tasksTimeFrom + (rand() % ((_userInput.tasksTimeTo / 2) - _userInput.tasksTimeFrom + 1));

		tasks.push_back(task);
		idCounter++;
	}

	return tasks;
}

vector<Member> Generator::generateMembers() const {
	vector<Member> members;
	int idCounter = 1;

	for (int i = _userInput.membersFrom; i <= _userInput.membersTo; i++) {
		Member member{};

		member.id = idCounter;
		member.experience = (static_cast<float>(_userInput.memberExperienceFrom) + (rand() % (_userInput.memberExperienceTo - _userInput.memberExperienceTo + 1))) / 10;

		members.push_back(member);
		idCounter++;
	}

	return members;
}