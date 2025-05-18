#include <iostream>
#include <cstdlib>
using  namespace std;

enum enLevel {Easy=1,Med=2,Hard=3,Mix=4};
enum enOpType{Add=1,Sub=2,Multi=3,Div=4};
struct stQuestionInfo {
	int Num1,Num2;
	short QuestionNumber;
	enOpType OperationType;
	string Result;
	int UserAnswer;
	int RightAnswer;
	int NumOfTrue;
	int NumOfFalse;
	enLevel Level;
};

int RandomNumber(int from,int to)
{

	int Random = rand() % (to - from + 1) + from;
	return Random;
}

int ReadNumber()
{
	int Num;
	cout << "How many questions do you want to answer? ";
	cin >> Num;
	return Num;
}

enLevel QuestionsLevel()
{


	int Level;
	cout << "Enter Questions Level [1]Easy,[2]Med,[3]Hard,[4]Mix? ";
	cin >> Level;
	return enLevel(Level);
}

int ReadNumbers(enLevel Level)
{
	int Num;
	switch (Level)
	{
	case enLevel::Easy:
		Num = RandomNumber(1, 10);
		break;
	case enLevel::Med:
		Num = RandomNumber(10, 40);
		break;
	case enLevel::Hard:
		Num = RandomNumber(40, 70);
		break;
	case enLevel::Mix:
	    Num = RandomNumber(1, 70);
		break;
	}
	return Num;
}

enOpType ReadOpType()
{



	int OpType;
	cout << "Enter Operation Type [1]Add,[2]Sub,[3]Multi,[4]Div,[5]Mix ?";
	cin>>OpType;
	return enOpType(OpType);
}

enOpType CheckMix(int OpType)
{


	if (OpType == 5)
		return enOpType(RandomNumber(1, 4));
	else
		return enOpType (OpType);
}

int ReadPlayerAnswer()
{

	int Answer;
	cin >> Answer;
	return Answer;
}

void OperationType()
{

	stQuestionInfo Info;
	switch (Info.OperationType)
	{
	case enOpType::Add:
		cout << "+";
		break;
	case enOpType::Sub:
		cout << "-";
		break;
	case enOpType::Multi:
		cout << "*";
		break;
	case enOpType::Div:
		cout << "/";
		break;
	}
}

int CalculateRigthAnswer(stQuestionInfo Info)
{

	switch (Info.OperationType)
	{
	case enOpType::Add:
		return Info.Num1 + Info.Num2;
	case enOpType::Sub:
		return Info.Num1 - Info.Num2;
	case enOpType::Multi:
		return Info.Num1 * Info.Num2;
	case enOpType::Div:
		return Info.Num1 / Info.Num2; 
	}
}

char GetOpSympol(enOpType Op)
{
	switch (Op)
	{
	case enOpType::Add:
		return '+';
	case enOpType::Sub:
		return '-';
	case enOpType::Multi:
		return 'x';
	case enOpType::Div:
		return '/';
	}

}

string GetOpName(enOpType Op)
{
	if (Op != 1 ||Op!=2 || Op!=3 || Op!=4)
		return "Mix";
	switch (Op)
	{
	case Add:
		return "Add";
	case Sub:
		return "Sub";
	case Multi:
		return "Multi";
	case Div:
		return "Div";
	}
}

void ShowQuestion(stQuestionInfo Info)
{
	cout << Info.Num1 << endl;
	cout << Info.Num2 << " " <<GetOpSympol(Info.OperationType) << endl;
	cout << "__________" << endl;
}

stQuestionInfo PlayGame(int HowManyQuestions)
{
		stQuestionInfo Info;
		enOpType Op;
		int NumOfTrue=0, NumOfFalse=0;
		Info.Level = QuestionsLevel();
		Op = ReadOpType();
		for (int i = 1; i <= HowManyQuestions; i++)
		{
			if (Op == 1 || Op == 2 || Op == 3 || Op == 4)
			{
				 Info.OperationType=Op;
			}
			else
			{
				Info.OperationType=enOpType(RandomNumber(1, 4));
			}
			Info.Num1 = ReadNumbers(Info.Level);
			Info.Num2 = ReadNumbers(Info.Level);
			cout << "\nQuestion [" <<i<<"/"<<HowManyQuestions<<"]\n";
			ShowQuestion(Info);
			Info.UserAnswer = ReadPlayerAnswer();
			Info.RightAnswer = CalculateRigthAnswer(Info);
			if (Info.UserAnswer == Info.RightAnswer)
			{
				NumOfTrue++;
				cout << "Rigth Answer :-)\n";
				system("color 2F");
			}
			else
			{
				NumOfFalse++;
				cout << "Wrong Answer :-(\n\a";
				system("color 4F");
			}
		}
		Info.NumOfTrue = NumOfTrue;
		Info.NumOfFalse = NumOfFalse;
		Info.QuestionNumber = HowManyQuestions;
		return Info;
}

stQuestionInfo PrintFinalResult(stQuestionInfo Info)
{
	cout << "___________________________________\n";
	if (Info.NumOfTrue >= Info.NumOfFalse)
	{
		cout << "Final Result is Pass\n";
		system("color 2F");
	}
	else
	{
		cout << "Final Result is Fail\n";
		system("color 4F");
	}
	cout << "___________________________________\n";
	cout << "Number Of Questions: " << Info.QuestionNumber << endl;
	cout << "Question Level\t:" << Info.Level << endl;
	cout << "OpType\t:" <<GetOpName( Info.OperationType) << endl;
	cout << "Number Of Rigth Answer:" << Info.NumOfTrue << endl;
	cout << "Number Of Wrong Answer:" << Info.NumOfFalse << endl;
	cout << "____________________________________________\n";

	return Info;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain='Y';
	do
	{
	ResetScreen();
	int Questions = ReadNumber();
	stQuestionInfo Info=PlayGame(Questions);
	PrintFinalResult(Info);

	cout << "Do You Want to Play Again";
	cin >> PlayAgain;
	} while (PlayAgain=='y' || PlayAgain=='Y');

}
int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}