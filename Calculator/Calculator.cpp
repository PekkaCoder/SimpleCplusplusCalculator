#include <iostream>
#include <string>

using namespace std;

enum class CalculatorOperation : char { None=0, Plus, Minus, Multiply, Divide, Exit };

CalculatorOperation askOperation()
{
	int selection;
	CalculatorOperation operation;
	cout << "Please select the operation: Plus (1), Minus (2), Multiply (3), Divide (4), Exit (0)" << endl;
	cin >> selection;
	switch (selection)
	{
	case 0:
		operation = CalculatorOperation::Exit;
		break;
	case 1:
		operation = CalculatorOperation::Plus;
		break;
	case 2:
		operation = CalculatorOperation::Minus;
		break;
	case 3:
		operation = CalculatorOperation::Multiply;
		break;
	case 4:
		operation = CalculatorOperation::Divide;
		break;
	default:
		operation = CalculatorOperation::None;
	}
	return operation;
}

void askTwoNumbers(double& firstNumber, double& secondNumber, string header)
{
	cout  << "***" << header  << "***" << endl;
	cout << "Fist number: ";
	cin >> firstNumber;
	cout << "Second number: ";
	cin >> secondNumber;
}

double addNumbers()
{
	double firstNumber, secondNumber;
	askTwoNumbers(firstNumber, secondNumber, "Adding numbers");
	return firstNumber + secondNumber;
}

double subtractNumbers()
{
	double firstNumber, secondNumber;
	askTwoNumbers(firstNumber, secondNumber, "Subtracting numbers");
	return firstNumber - secondNumber;
}

double multiplyingNumbers()
{
	double firstNumber, secondNumber;
	askTwoNumbers(firstNumber, secondNumber, "Multiplying numbers");
	return firstNumber * secondNumber;
}

double dividingNumbers()
{
	double firstNumber, secondNumber;
	do {
		askTwoNumbers(firstNumber, secondNumber, "Dividing numbers");
		if (secondNumber == 0.0)
			cout << "Can not divide by zero. Please enter numbers again." << endl;
	} while (secondNumber == 0.0);
	return firstNumber / secondNumber;
}

double handleOperation(CalculatorOperation operation)
{
	double result;
	switch (operation)
	{
	case CalculatorOperation::Plus:
		result = addNumbers();
		break;
	case CalculatorOperation::Minus:
		result = subtractNumbers();
		break;
	case CalculatorOperation::Multiply:
		result = multiplyingNumbers();
		break;
	case CalculatorOperation::Divide:
		result = dividingNumbers();
		break;
	}

	return result;
}

void runCalculator()
{
	double result;
	CalculatorOperation operation = CalculatorOperation::None;
	cout << "Welcome to calculating numbers!" << endl;
	while (operation != CalculatorOperation::Exit)
	{
		// keep asking operation until it is a valid operator
		do {
			operation = askOperation();
			if (operation == CalculatorOperation::None)
				cout << "Unknown selection. Please select again." << endl;
		} while (operation == CalculatorOperation::None);

		if (operation != CalculatorOperation::Exit)
		{
			result = handleOperation(operation);
			cout << "The result is: " << result << endl;
		}
	}
	cout << "Thank you for using this calculator" << endl;
}

int main()
{
	runCalculator();
	
    return 0;
}

