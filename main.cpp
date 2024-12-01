/* 
Author: Aidan P
File Created: 11/30/24 
Purpose: Take in a string input and convert it to a double-number without using standard c++ libraries
Collaborators: None
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// function prototypes
double extractNumeric(string str);

int main()
{
	// Code inspired by the example given in lab
    string input;

    while (true) {
		// Take in a string
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

		// end program if the input matches the determined phrase
        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

		// handle errors (represented by the return value of -999999.99 from the extractNumeric function) 
        if (number != -999999.99) {
            cout << "The number is: " << fixed << setprecision(4) << number << endl;
        }
        else {
            cout << "The input is invalid." << endl;
        }
    }
}

double extractNumeric(string input)
{
	// declare variables
	double num = 0;
	bool isNegative = false;
	bool isDecimal = false;
	int decimalCount = 0;
	int pos = -1; int decimalPos = -1;

	// check if the number is negative or positive
	if (input[0] == '-') {
		isNegative = true;
		input.erase(0, 1);
	}
	else if (input[0] == '+') {
		input.erase(0, 1);
	}


	// check to make sure string input is valid/all characters are numeric
	for (char c : input) {
		pos++;
		int cNum = c - '0';
		if (cNum > 9 || (cNum < 0 && cNum != -2)) {
			// return invalid data if non-numeric characters are detected
			return -999999.99;
		}
		else if (c == '.') {
			decimalCount++;
			decimalPos = pos;
			isDecimal = true;
			// check to make sure multiple decimal points aren't in the input, and handle accordingly if so
			if (decimalCount > 1) {
				return -999999.99;
			}
		}
	}

	// start reading the string into a double num
	int decimalPosTheSequel = 0;
	for (char c : input) {
		if (c == '.') {
			continue;
		}
		num = (num * 10) + (c - '0');
		decimalPosTheSequel++;
	}

	// handle decimal position if there is one (divide by the number of spaces after decimal)
	if (isDecimal) {
		num /= pow(10, decimalPosTheSequel - decimalPos);
	}

	// flip to negative if input was negative 
	if (isNegative) {
		num *= -1;
	}
	return num;

}

