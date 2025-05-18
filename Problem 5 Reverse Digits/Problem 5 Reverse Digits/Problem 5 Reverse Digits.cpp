#include <iostream>
using namespace std;

int ReadNumber(string message)
{
	int Num;
	cout << message << endl;
	cin >> Num;
	return Num;
}
int ReverseDigits(int Num)
{
	int x = 0;
	int Num2=0;
	
	while (Num > 0)
	{
		x = Num % 10;
		Num = Num / 10;
		Num2 = Num2 * 10 + x;
		//or
		//cout<<x; without Num2 var
	}
	return Num2;
}
//void PrintDigits(int Num)
//{
//	while (Num > 0)
//	{
//		cout << ReverseDigits(Num) << endl;
//	}
//}
int main()
{
	cout<<"\nReversed is:\n"<<ReverseDigits(ReadNumber("Please Enter Number"));
	
}

