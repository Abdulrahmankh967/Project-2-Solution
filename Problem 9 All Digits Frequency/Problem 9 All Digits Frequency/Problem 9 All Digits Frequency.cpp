#include <iostream>
using namespace std;

int ReadNumber(string message)
{
	int Num;
	cout << message << endl;
	cin >> Num;
	return Num;
}
int DigitFrequency(short Digit,int Num)
{
	int x=0;
	int count=0;
	while (Num > 0)
	{
			x = Num % 10;
			Num = Num / 10;
			if (Digit==x)
			{
				count++;
			}
	}
	      return count;
	
}
void PrintFrequency(int Num)
{
	for (int i = 0; i < 10; i++)
	{
		short Counter = 0;
		Counter = DigitFrequency(i,Num);
		if (Counter > 0)
		{
			cout << endl << "Digit " << i << " Frequency is " << Counter << " Time(s)." << endl;
		}
	}
}

int main()
{
	int Num = ReadNumber("Please Enter Number");
	PrintFrequency(Num);
}

