#include <iostream>
using namespace std;

int ReadNumber(string message)
{
	int Num;
	cout << message << endl;
	cin >> Num;
	return Num;
}
int DigitFrequency(int Num,short Digit)
{
	int x = 0;
	int count=0;
	while (Num > 0)
	{
		x = Num % 10;
		Num = Num / 10;
		if (x == Digit)
		{
			count++;
		}
	}
	return count;
}
void PrintFrequency(int Num,short Digit)
{
			cout << endl << "Digit " << Digit << " Frequency is " << DigitFrequency(Num, Digit) << " Time(s)." << endl;
}
int main()
{
	int Num = ReadNumber("Please Enter Number");
    short Digit = ReadNumber("Please Enter Digit");
	PrintFrequency(Num,Digit);
}

