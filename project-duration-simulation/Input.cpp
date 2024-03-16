#include "Input.h"

string Input::_crt = "----------------------------------------------------------------------------------------------------";
string Input::_dot = "....................................................................................................";

void Input::inputTemplate(string inputMessage, string errorMessage, int& inputObject, int min, int max) {
	while (cout << inputMessage, cin >> inputObject, (inputObject <= min || inputObject >= max)) {
		cout << errorMessage << endl;
	}
}

InputResponse& Input::userInput() {
	InputResponse userInput{};

	cout << _crt << endl;

	cout << "TASK RELATED DATA" << endl;

	cout << _dot << endl;

	cout << "Enter the range of the numbers of tasks." << endl;

	inputTemplate(string("Tasks -> from: "), string("Invlaid number"), userInput.tasksFrom, 0, INT16_MAX);
	inputTemplate(string("Tasks -> to: "), string("Invlaid number"), userInput.tasksTo, userInput.tasksFrom, INT16_MAX);

	cout << _dot <<endl;

	cout << "Enter the range of task duration (hours)." << endl;

	inputTemplate(string("Task time -> from: "), string("Invlaid number"), userInput.tasksTimeFrom, 0, INT16_MAX);
	inputTemplate(string("Task time -> to: "), string("Invlaid number"), userInput.tasksTimeTo, userInput.tasksTimeFrom, INT16_MAX);

	cout << _dot << endl;

	cout << "Enter the limit to witch the tasks request changing probability can generated." << endl;

	inputTemplate(string("Enter value (1 - 100): "), string("Invlaid number"), userInput.requestChangeProbabilityValue, 0, 101);

	cout << _dot << endl;

	cout << "Do you want to simulate the probability of tasks request changing or to incalculate it?" << endl;
	cout << "0 - simulate" << endl;
	cout << "1 - incalculate" << endl;

	inputTemplate(string("Enter option: "), string("Invalid number"), userInput.requestChangeProbabilityType, -1, 2);

	cout << _crt << endl;

	cout << "MEMBERS RELATED DATA" << endl;

	cout << _dot << endl;

	cout << "Enter the range of the numbers of members." << endl;

	inputTemplate(string("Members -> from: "), string("Invlaid number"), userInput.membersFrom, 0, INT16_MAX);
	inputTemplate(string("Members -> to: "), string("Invlaid number"), userInput.membersTo, userInput.membersFrom, INT16_MAX);

	cout << _dot << endl;

	cout << "Enter the range of member experience (range: 1 - 20)." << endl;
	cout << "*Experience under 10 - more experienced*" << endl;
	cout << "*Experience over 10 - less experienced*" << endl;

	inputTemplate(string("Member experience -> from: "), string("Invlaid number"), userInput.memberExperienceFrom, 0, 21);
	inputTemplate(string("Member experience -> to: "), string("Invlaid number"), userInput.memberExperienceTo, userInput.memberExperienceFrom, 21);

	cout << _crt << endl;

	cout << "MONTE CARLO SIMULATION RELATED DATA" << endl;

	cout << _dot << endl;

	cout << "Chose the Monte Carlo simulation option:" << endl;
	cout << "1 - fixed data " << endl;
	cout << "2 - random data " << endl;
	cout << "3 - both " << endl;

	inputTemplate(string("Enter option: "), string("Invalid number"), userInput.monteCarloOption, 0, 4);

	cout << _dot << endl;

	inputTemplate(string("Enter the number of Monte Carlo simulation iterations: "), string("Invlaid number"), userInput.monteCarloIterations, 0, INT16_MAX);

	cout << _crt << endl;

	cout << "SAVING DATA" << endl;

	cout << _dot << endl;

	cout << "Do you want to save the generated data into CSV files?" << endl;
	cout << "0 - no" << endl;
	cout << "1 - yes" << endl;

	inputTemplate(string("Enter option: "), string("Invalid number"), userInput.saveData, -1, 2);

	cout << _crt << endl;

	system("CLS");
	return userInput;
}