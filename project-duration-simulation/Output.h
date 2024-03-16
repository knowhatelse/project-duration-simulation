#pragma once

#ifndef OUTPUT_H
#endif // !OUTPUT_H

#include <iostream>
#include "OutputResponse.h"

using namespace std;

class Output {
	static string _crt;
	static string _dot;

public:
	static void programOutput(OutputResponse& outputResponse);
};