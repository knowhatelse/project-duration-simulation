#pragma once

#ifndef TASK.H
#endif // !TASK.H

#include "Member.h"

struct Task {
	int id;

	int optimisticTime;
	int pessimisticTime;
	int mostLikelyTime;

	float requestChangeProbabilityValue;
	int delayTime;

	float estimatedTime;

	Member member;
};