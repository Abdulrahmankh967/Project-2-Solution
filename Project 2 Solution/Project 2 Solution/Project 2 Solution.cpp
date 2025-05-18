#include <iostream>
#include <cstdlib>
using namespace std;

enum enLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };

enum enOpType { Add = 1, Sub = 2, Multi = 3, Div = 4,Mixop=5};


struct stQuestionInfo {
	int Num1=0, Num2=0;
	short QuestionNumber;
	enOpType OperationType;
	enLevel QuestionLevel;
	int UserAnswer=0;
	int RightAnswer=0;
	bool AnswreResult = false;
	
};

struct stQuizz {
	stQuestionInfo QuestionsList[100];
	short NumberOfQuestions;
	enOpType OpType;
	enLevel QuestionsLevel;
	short NumOfRigth=0;
	short NumOfWrong=0;
	bool isPass = false;

};

short ReadHowManyQuestions()
{
	int Questions;
	do
	{
		cout << "How many questions do you want to answer ? ";
		cin >> Questions;
	} while (Questions<1 || Questions>10);
	return Questions;
}

enLevel ReadQuestionsLevel()
{
	short Level;
	do
	{
	cout << "Enter Questions Level [1]Easy,[2]Med,[3]Hard,[4]Mix? ";
	cin >> Level;
	} while (Level<1 || Level>4);
	return enLevel(Level);
}

enOpType ReadOpType()
{
	int OpType;
	do
	{
		cout << "Enter Operation Type [1]Add,[2]Sub,[3]Multi,[4]Div,[5]Mix ?";
		cin >> OpType;
	} while (OpType < 1 || OpType>5);
	return enOpType(OpType);
}

int RandomNumber(int from, int to)
{

	int Random = rand() % (to - from + 1) + from;
	return Random;
}

int SimpleCalculator(int Number1,int Number2,enOpType OpType)
{
	switch (OpType)
	{
	case enOpType::Add:
		return Number1 + Number2;
	case enOpType::Sub:
		return Number1 - Number2;
	case enOpType::Multi:
		return Number1 * Number2;
	case enOpType::Div:
		return Number1/Number2;
	default:
		return Number1 + Number2;
	}
}

enOpType GetRandomOperationType()
{
	return enOpType(RandomNumber(1, 4));
}

string GetQuestionLevelText(enLevel QuestionLevel)
{
	string arrQuestionLevel[4] = {"Easy","Med","Hard","Mix"};
	return arrQuestionLevel[QuestionLevel - 1];
}

string GetOperationTypeSymbole(enOpType OpType)
{
	switch (OpType)
	{
	case Add:
		return "+";
	case Sub:
		return "-";
	case Multi:
		return "x";
	case Div:
		return "/";
	default:
		return "Mix";
	}
}

string GetFinalReultText(bool Pass)
{
	if (Pass)
	{
		system("color 2F");
		return "Pass";
	}
	else
	{
		system("color 4F");
		return "Fail";
	}
}

stQuestionInfo GenerateQuestion(enLevel Level, enOpType OpType)
{
	stQuestionInfo Info;
	if (Level ==enLevel::Mix)
	{
		Level =enLevel( RandomNumber(1, 3));
	}
	if (OpType == enOpType::Mixop)
	{
		OpType = GetRandomOperationType();
	}
	Info.OperationType = OpType;
	switch (Level)
	{
	case enLevel::Easy:
		Info.Num1 = RandomNumber(1, 10);
		Info.Num2 = RandomNumber(1, 10);
		Info.RightAnswer = SimpleCalculator(Info.Num1, Info.Num2, Info.OperationType);
		Info.QuestionLevel = Level;
		return Info;
	case enLevel::Med:
		Info.Num1 = RandomNumber(10, 50);
		Info.Num2 = RandomNumber(10, 50);
		Info.RightAnswer = SimpleCalculator(Info.Num1, Info.Num2, Info.OperationType);
		Info.QuestionLevel = Level;
		return Info;
	case enLevel::Hard:
		Info.Num1 = RandomNumber(50, 100);
		Info.Num2 = RandomNumber(50, 100);
		Info.RightAnswer = SimpleCalculator(Info.Num1, Info.Num2, Info.OperationType);
		Info.QuestionLevel = Level;
		return Info;
	}
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
	for (int i = 0; i < Quizz.NumberOfQuestions; i++)
	{
		Quizz.QuestionsList[i] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
	}
}

int ReadPlayerAnswer()
{

	int Answer;
	cin >> Answer;
	return Answer;
}

void SetColorScreen(stQuizz &Quizz,short QuestionNumber)
{
	if (Quizz.QuestionsList[QuestionNumber].AnswreResult == true)
	{
		system("color 2F");
	}
	else
	{
		cout << "\a";
		system("color 4F");
	}
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionsList[QuestionNumber].RightAnswer != Quizz.QuestionsList[QuestionNumber].UserAnswer)
	{
		Quizz.QuestionsList[QuestionNumber].AnswreResult =false;
		Quizz.NumOfWrong++;
		cout << "Wrong Answer :-(\n";
		SetColorScreen(Quizz, QuestionNumber);
		cout << "The Rigth Answer is: " << Quizz.QuestionsList[QuestionNumber].RightAnswer<<endl;
	}
	else
	{
		Quizz.QuestionsList[QuestionNumber].AnswreResult = true;
		Quizz.NumOfRigth++;
		SetColorScreen(Quizz, QuestionNumber);
		cout << "Rigth Answer :-)\n";
	
	}
}

void PrintTheQuestion(stQuizz &Quizz,short QuestionNumber)
{
	cout << endl;
	
	cout << "Question[" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
	cout << "___________\n";
	cout << Quizz.QuestionsList[QuestionNumber].Num1 << endl;
	cout << Quizz.QuestionsList[QuestionNumber].Num2 <<" ";
	cout <<GetOperationTypeSymbole( Quizz.QuestionsList[QuestionNumber].OperationType )<< endl;
	cout << "_____________\n";
}

void AskandCorrectQuestionListAnswer(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
	{
		PrintTheQuestion(Quizz,QuestionNumber);
		Quizz.QuestionsList[QuestionNumber].UserAnswer = ReadPlayerAnswer();
		
		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}
	Quizz.isPass = (Quizz.NumOfRigth >= Quizz.NumOfWrong);
}

void PrintFinalResult(stQuizz Info)
{
	cout << "__________________________________\n";
	cout << "Final Result is " << GetFinalReultText(Info.isPass)<<endl;
	cout << "\n___________________________________\n";
	cout << "Number Of Questions: " << Info.NumberOfQuestions << endl;
	cout << "Question Level\t:" <<GetQuestionLevelText( Info.QuestionsLevel) << endl;
	cout << "OpType\t:" <<GetOperationTypeSymbole(Info.OpType)<< endl;
	cout << "Number Of Rigth Answer:" << Info.NumOfRigth << endl;
	cout << "Number Of Wrong Answer:" << Info.NumOfWrong << endl;
	cout << "____________________________________________\n";
}

void PlayMathGame()
{
	stQuizz Quizz;
	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionsLevel = ReadQuestionsLevel();
	Quizz.OpType = ReadOpType();
	GenerateQuizzQuestions(Quizz);
	AskandCorrectQuestionListAnswer(Quizz);


	PrintFinalResult(Quizz);
	
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
		PlayMathGame();
		cout << "Do You Want to Play Again? ";
		cin >> PlayAgain;
	} while (PlayAgain=='Y' || PlayAgain=='y');
}


int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}

