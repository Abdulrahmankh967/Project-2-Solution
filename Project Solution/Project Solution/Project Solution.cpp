#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2,Secssiors=3};
enum enWinner { Player1 = 1, Computer = 2,Draw=3};

struct stRoundInfo {
	short RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName="";
};

struct stGameResult {

	int GameRounds;
	short Player1WinTimes, ComputerWinTimes, DrawTimes;
	enWinner GameWinner;
	string WinnerName="";
};

int RandomNumber(int from, int to)
{
	int RandNum;
	RandNum = rand() % (to - from + 1) + from;
	return RandNum;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
		return enWinner::Draw;
	switch (RoundInfo.PlayerChoice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Secssiors)
		{
			return enWinner::Computer;
		}
	case enGameChoice::Secssiors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
	}
		return enWinner::Player1;
	
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (Player1WinTimes < ComputerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

string ChoiceName(int Choice)
{
	string arrWinnerName[3] = { "Stone","Paper","Secssiors" };
	return arrWinnerName[Choice - 1];
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1","Computer","Draw" };
	return arrWinnerName[Winner - 1];
}

enGameChoice ReadPlayer1Choice()
{
	short Choice = 0;
	do
	{
		cout << "\nYour Choice: [1] Stone, [2] Paper, [3] Secssiors ?";
		cin >> Choice;

	} while (Choice>3 || Choice<1);
	return enGameChoice(Choice);
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
	cout << "\n______________Round[" << RoundInfo.RoundNumber << "]____________\n\n";
	cout << "Player1 Choice:" <<ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice:" << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner: [" << RoundInfo.WinnerName <<"]"<< endl;
	cout << "_______________________________________________\n" << endl;

}

int ReadHowManyRounds()
{
	short Rounds = 0;
	do
	{
		cout << "How Many Rounds 1 to 10?\n";
		cin >> Rounds;
	} while (Rounds > 10 || Rounds < 1);

	return Rounds;
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");
		break;
	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;
	case enWinner::Draw:
		system("color 6F");
		break;
	}
}

stGameResult FillGameResult(short GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResult GameResults;
	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

stGameResult PlayGame(short HowManyRound)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	for (int GameRound = 1; GameRound <= HowManyRound; GameRound++)
	{
		cout << "Round [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;
		SetWinnerScreenColor(RoundInfo.Winner);
		PrintRoundResult(RoundInfo);
	}
	return FillGameResult(HowManyRound, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
	string t = "";
	for (int i =1; i<NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "_________________________________________\n\n";
	cout << Tabs(2) << "             +++ G a m e O v e r +++\n";
	cout << Tabs(2) << "________________________________________\n\n";

}

void ShowFinalGameResult(stGameResult GameResult)
{
	cout<<Tabs(2) << "___________________[Game Result]___________________________\n\n";
	cout<<Tabs(2) << "Game Rounds       :" <<GameResult.GameRounds<< endl;
	cout<<Tabs(2) << "Player1 Won times: " <<GameResult.Player1WinTimes << endl;
	cout<<Tabs(2) << "Computer Won times:" <<GameResult.ComputerWinTimes << endl;
	cout<<Tabs(2) << "Draw Times :" << GameResult.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner:          " << GameResult.WinnerName << endl;
	cout<<Tabs(2)<< "____________________________________________________________";

	SetWinnerScreenColor(GameResult.GameWinner);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		stGameResult GameResult = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResult(GameResult);

		cout << endl << Tabs(3) << "Do You Want to Play Again Y/N?";
		cin >> PlayAgain;

	} while (PlayAgain=='Y' || PlayAgain=='y');
}

int main()
{
    srand((unsigned)time(NULL));
	StartGame();
}

