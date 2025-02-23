#include <iostream>
#include <cstdlib>
using namespace std;


int GetRandom(int from, int to) {
	return from + rand() % (to - from + 1);
}

int ReadNumberInRange(string mssg,int from,int to)
{
	int number;
	do
	{
		cout << mssg;
		cin >> number;
	} while (number<from||number>to);
	return number;
}

int InGameRounds()
{
	int roundsNo = ReadNumberInRange("How many rounds from 1 to 10? ",1,10);
	return roundsNo;
}

enum enGameChoice{Stone=1,Paper=2,Scissors=3};
enum enRoundWinState{User=1,Computer=2,NoWinner=3};

enGameChoice ReadChoice (int number)
{
	return enGameChoice(number);
}

string ChoiceToString(enGameChoice Choice)
{
	if (Choice == enGameChoice::Paper)
		return "Paper";
	else if (Choice == enGameChoice::Scissors)
		return "Scissors";
	else if (Choice == enGameChoice::Stone)
		return "Stone";
}

string enRoundWinStateToString (enRoundWinState WinState)
{
	if (WinState == enRoundWinState::Computer)
		return "Computer";
	else if (WinState == enRoundWinState::User)
		return "User";
	else if (WinState == enRoundWinState::NoWinner)
		return "No Winner";
}


void PrintRoundResult(int RoundNumber, enRoundWinState Winstate, enGameChoice UserChoice, enGameChoice ComputerChoice)
{
	cout << "\n___________________________Round [" << RoundNumber+1 << "]___________________________\n";
	cout << "User Choice: " << ChoiceToString(UserChoice)<<endl;
	cout << "Computer choice: " << ChoiceToString(ComputerChoice)<<endl;
	cout << "Round Winner: " << enRoundWinStateToString(Winstate)<<endl;
	cout<< "\n________________________________________________\n";
}

string FinalWinner(int UserWinCount, int ComputerWinCount,int DrawCount)
{
	if (UserWinCount > ComputerWinCount) 
	{
		if (UserWinCount > DrawCount)
		{
			return "User";
		}
		return "Draw";
	}
	else
	{
		if (ComputerWinCount > DrawCount)
			return "Computer";
		else
			return "No Winner";
	}	
}

void GameOver(int NumberOfRounds, int UserWinCount, int ComputerWinCount, int DrawCount, string FinalWinner)
{
	cout << "\n\t\t_________________________________________________________\n";
	cout << "\n\t\t\t\t +++ G a m e  O v e r +++ \t\t";
	cout << "\n\t\t_________________________________________________________\n";
	cout << "\n\n\t\t_______________________[Game Results]____________________\n\n";
	cout << "\t\tGame Rounds\t\t: " << NumberOfRounds << endl;
	cout << "\t\tPlayer1 won times\t: " << UserWinCount << endl;
	cout << "\t\tComputer won times\t: " << ComputerWinCount << endl;
	cout << "\t\tDraw times\t\t: " << DrawCount << endl;
	cout << "\t\tFinal Winner\t\t: " << FinalWinner << endl;
	cout << "\n\t\t____________________________________\n";
}

void BeignRounds(int NumberOfRounds)
{
	int number;
	int UserWinCount = 0, ComputerWinCount = 0, DrawCount = 0;

	for (int i = 0; i < NumberOfRounds; ++i)
	{
		number = ReadNumberInRange("\nYour choice: [1]: Stone [2]:Paper [3]:Scissors?:\n", 1, 3);
		cout << "\nRound [" << i + 1<< "] " << "Begins: \n" << endl;
		enGameChoice UserChoice = ReadChoice(number);
		enGameChoice ComputerChoice = ReadChoice(GetRandom(1, 3));
		enRoundWinState RoundWinner;
		string choice;

		if (UserChoice == enGameChoice::Paper && ComputerChoice == enGameChoice::Stone) //1.stone paper case
		{
			RoundWinner = enRoundWinState::User;
			system("color 2f");
			UserWinCount++;
		}
		else if (UserChoice == enGameChoice::Stone && ComputerChoice == enGameChoice::Paper)
		{
			RoundWinner = enRoundWinState::Computer;
			cout << "\a";
			system("color 4f");
			ComputerWinCount++;
		}
			
		else if (UserChoice == enGameChoice::Stone && ComputerChoice == enGameChoice::Scissors) //2.
		{
			RoundWinner = enRoundWinState::User;
			system("color 2f");
			UserWinCount++;
		}
		else if (UserChoice == enGameChoice::Scissors && ComputerChoice == enGameChoice::Stone)
		{
			RoundWinner = enRoundWinState::Computer;
			cout << "\a";
			system("color 4f");

			ComputerWinCount++;
		}
		else if (UserChoice == enGameChoice::Scissors && ComputerChoice == enGameChoice::Paper)
		{
			RoundWinner = enRoundWinState::User;
			system("color 2f");
			UserWinCount++;
		}
		else if (UserChoice == enGameChoice::Paper && ComputerChoice == enGameChoice::Scissors)
		{
			RoundWinner = enRoundWinState::Computer;
			cout << "\a";
			system("color 4f");
			ComputerWinCount++;
		}
		else if (UserChoice == ComputerChoice)
		{
			RoundWinner = enRoundWinState::NoWinner;
			++DrawCount;
			system("color 6f");
		}
		PrintRoundResult(i, RoundWinner, UserChoice, ComputerChoice);			
	}
	string finalwinner = FinalWinner (UserWinCount, ComputerWinCount, DrawCount);
	GameOver(NumberOfRounds, UserWinCount, ComputerWinCount, DrawCount, finalwinner);
}
void ResetScreen()
{
	system("cls");
	system("color 07");

}

void StartGame()
{
	int counter = 0;
	while (1)
	{
		int NumberOfRounds = InGameRounds();
		BeignRounds(NumberOfRounds);
		int Number = ReadNumberInRange("\nDo you want to play again [1]Yes [0]No ?" ,0, 1);
		if (Number == 1)
			ResetScreen();
		else
			break;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();	
}
