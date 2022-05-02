/*
Daniel Breslin
5/2/2022
Exceptions
*/

#include<iostream>
#include<string>

bool Validate_Character(char letter);
void Validate_Range(int endPosition);
char Character(char start, int offset);

using namespace std;

int main()
{
	bool again = true;
	bool takingInput;
	char letter;
	int offset;

	while (again)
	{
		takingInput = true;
		while (takingInput)
		{
			try
			{
				cout << "\nPlease enter a letter: ";
				cin >> letter;

				takingInput = Validate_Character(letter);
			}
			catch (string invalidCharacterException)
			{
					cout << invalidCharacterException;
			}
		}

		cout << "\nPlease enter the offset from the letter: ";
		cin >> offset;

		letter = Character(letter, offset);

		if (isalpha(letter))
		{
			cout << "\nThe result is: " << letter;
		}

		cout << "\nWould you like try again? Press 1 for yes and 0 for no: ";
		cin >> again;
	}


}

char Character(char start, int offset)
{
	const int NUM_LETTERS = 26;
	int letterPosition[NUM_LETTERS] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };
	char upperLetters[NUM_LETTERS] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char lowerLetters[NUM_LETTERS] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	// Match the letter to a number to try operation idk.
	int index = 0;
	int position = -1;
	int endPosition;
	bool found = false;
	string type;

	while (index < NUM_LETTERS && found == false)
	{
		if (upperLetters[index] == start)
		{
			found = true;
			position = index;
			type = "upper";
		}
		else if (lowerLetters[index] == start)
		{
			found = true;
			position = index;
			type = "lower";
		}

		if (!found)
		{
			index++;
		}
	}

	try
	{
		endPosition = (position + offset);
		Validate_Range(endPosition);
		if (type == "upper")
		{
			return upperLetters[endPosition];
		}
		else if (type == "lower")
		{
			return lowerLetters[endPosition];
		}
	}
	catch (string invalidRangeException)
	{
		cout << invalidRangeException;
	}

}

bool Validate_Character(char letter)
{
	bool invalid;
	string invalidCharacterException = "\nError: first input must be a letter.";

	if (!isalpha(letter))
	{
		invalid = true;
		throw invalidCharacterException;
	}
	else
	{
		invalid = false;
	}

	return invalid;
}


void Validate_Range(int endPosition)
{
	string invalidRangeException = "\nError: offset would land outside the English alphabet.";

	if (endPosition > 25 || endPosition < 0)
	{
		throw invalidRangeException;
	}
}
