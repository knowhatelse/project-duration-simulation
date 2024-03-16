#pragma once

#ifndef ASSIGN_H
#endif // !ASSIGN_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Member.h"
#include "Task.h"

using namespace std;

class Assign {
public:
	static void membersToTasks(vector<Member>& members, vector<Task>& tasks);
};