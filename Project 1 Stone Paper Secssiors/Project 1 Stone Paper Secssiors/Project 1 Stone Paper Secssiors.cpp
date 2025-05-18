#include <iostream>
#include <cstdlib>
using namespace std;
int ReadNumber(string msg) {
    int Num;
    cout << msg << std::endl;
    cin >> Num;
    return Num;
}


int RandomNumber(int from, int to)
{
    int RandNum;
    RandNum = rand() % (to - from + 1) + from;
    return RandNum;
}


int MyChoice()
{ 
     int  Choice;
        cout << "\nYour Choice: [1] Stone, [2] Paper, [3] Secssiors ?";
        cin >> Choice;
        return Choice;
}

int ComputerChoice()
{
   return RandomNumber(1, 3);
   
}

string ChoiceToString(int Choice)
{
    switch (Choice)
    {
    case 1:
        return "Stone";
    case 2:
        return "Paper";
    case 3:
        return "Secssiors";
    }
}

int CheckResult(int MyChoice, int ComputerChoice) {
    if (MyChoice == ComputerChoice)
        return 0; 
    if ((MyChoice == 1 && ComputerChoice == 3) ||
        (MyChoice == 2 && ComputerChoice == 1) ||
        (MyChoice == 3 && ComputerChoice == 2))
    {
        return 1;
    }
   
        return 2; 
}

void PrintRoundResult(int Round)
{
    int Play = 1;
    while (Play != 0)
    {
        Round = ReadNumber("How Many Rounds 1 to 10?");
        int Choice, computerChoice;
        int Player1 = 0, Computer = 0;
        for (int i = 1; i <= Round; i++)
        {
            Choice = MyChoice();
            computerChoice = ComputerChoice();
            cout << "Round [" << i << "] begin:\n";
            if (CheckResult(Choice, computerChoice) == 0)
            {
                cout << "\n------------Round[" << i << "]---------------\n";
                cout << "Player1 Choice:" << ChoiceToString(Choice) << endl;
                cout << "Computer Choice:" << ChoiceToString(computerChoice) << endl;
                cout << "Round Winner: [No Winner]" << endl;
                cout << "-------------------------------\n";
                system("color 6F");
            }
            else if (CheckResult(Choice, computerChoice) == 1)
            {
                cout << "\n------------Round[" << i << "]---------------\n";
                cout << "Player1 Choice:" << ChoiceToString(Choice) << endl;
                cout << "Computer Choice:" << ChoiceToString(computerChoice) << endl;
                cout << "Round Winner: [Player1 Winner]" << endl;
                cout << "-------------------------------\n";
                system("color 2F");
                Player1++;
            }
            else if (CheckResult(Choice, computerChoice) == 2)
            {
                cout << "\n------------Round[" << i << "]---------------\n";
                cout << "Player1 Choice:" << ChoiceToString(Choice) << endl;
                cout << "Computer Choice:" << ChoiceToString(computerChoice) << endl;
                cout << "Round Winner: [Computer Winner]" << endl;
                cout << "-------------------------------\n\a";
                system("color 4F");
                Computer++;
            }
        }
        cout << "\t\t------------------------------------------------\n";
        cout << "\n\t\t\t   +++ G a m e O v e r +++\n";
        cout << "\n\t\t------------------------------------------------\n";
        cout << "\n\t\t-------------------[Game Result]----------------\n";
        cout << "\n\t\tGame Rounds\t:" << Round << endl;
        cout << "\t\tPlayer1 Won times: " << Player1 << endl;
        cout << "\t\tComputer Won times: " << Computer << endl;
        cout << "\t\tDraw Times :" << Round - Player1 - Computer << endl;
        if (Player1 > Computer)
        {
            cout << "\t\tFinal Winner: Player1\n";
            system("color 2F");
        }

        else if (Computer > Player1)
        {
            cout << "\t\tFinal Winner: Computer\n\a";
            system("color 4F");
        }
        else
        {
            cout << "\t\tFinal Winner: No Winner\n";
            cout << "\t\t---------------------------------------------\n";
            system("color 6F");

        }
        cout << "\t\t------------------Do You Want to Play Again?--------------------\n";
        cin >> Play;
        system("cls");
        system("color 0F");
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int Round=0;
    PrintRoundResult(Round);
}

