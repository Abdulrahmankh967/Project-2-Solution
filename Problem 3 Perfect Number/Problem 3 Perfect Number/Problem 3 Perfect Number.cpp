#include <iostream>
using namespace std;

//enum enPerfectNotPerfect { Perfect = 1,NotPerfect=2 };

int ReadNumber(string message)
{
	int Num;
	cout << message << endl;
	cin >> Num;
	return Num;
}
//enPerfectNotPerfect CheckNumber(int Num)
bool CheckNumber(int Num)
{
	int sum = 0;
	for (int i = 1; i <= Num / 2; i++)
	{
		if (Num % i == 0)
		{
			sum += i;
		}
	}
	return Num == sum;
	//if (sum == Num)
	//	return enPerfectNotPerfect::Perfect;
	//else
	//	return enPerfectNotPerfect::NotPerfect;
}
void PrintType(int Num)
{
	for (int i = 1; i <= Num; i++)
	{
		if (CheckNumber(i))
			cout << i << " is Perfect Number" << endl;
	}
}
int main()
{
	PrintType(ReadNumber("Please Enter Number"));
}

