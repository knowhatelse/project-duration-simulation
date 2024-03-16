#pragma once

#ifndef GENERATOR_H
#endif // !GENERATOR_H

#include <vector>
#include "Task.h"
#include "Member.h"
#include "InputResponse.h"

using namespace std;

class Generator {
	InputResponse _userInput;

public:
	Generator(InputResponse& userInput);

	vector<Task> generateTasks() const;
	vector<Member> generateMembers() const;
};