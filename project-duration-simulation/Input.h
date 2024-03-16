#pragma once

#ifndef INPUT_H
#endif // !INPUT_H

#include <iostream>
#include "InputResponse.h"

using namespace std;

class Input {
	static string _crt;
	static string _dot;

	static void inputTemplate(string inputMessage, string errorMessage, int& inputObject, int min, int max);

public:
	static InputResponse& userInput();
};