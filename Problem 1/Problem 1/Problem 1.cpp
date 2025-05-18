#include <iostream>
using namespace std;
//My Solution
// 
//void PrintHi()
//{
//	cout << "\t\t Multiplication Table from 1 to 10\n\n\n\n    ";
//}
//void TableHeader()
//{
//
//	for (int i = 1; i <= 87; i++)
//	{
//		cout << "-";
//	}
//	cout << endl;
//	for (int x = 1; x <=10; x++)
//	{
//		cout <<x;
//		cout << "\t|";
//		for(int j = 1; j <= 10; j++)
//		{
//			cout << "  ";
//			cout << x * j<<"\t";
//		}
//		cout << "\n";
//	}
//
//}
//void PrintUpNumber()
//{
//	for (int i = 1; i <= 10; i++)
//	{
//		cout << "\t";
//		cout << "  ";
//		cout << i;
//	}
//	 cout<< endl;
//}
//
//int main()
//{
//	PrintHi();
//	PrintUpNumber();
//	TableHeader();
//}


//Dr Solution

void PrintTableHeader()
{
	cout << "\t\t Multiplication Table from 1 to 10\n\n\n\n";
	cout << "\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << "\n-----------------------------------------------------------------------------------\n";
}
string ColumSperator(int i)
{
	if (i < 10)
		return "   |";
	else
		return "  |";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();
	for (int i = 1; i <= 10; i++)
	{
		cout << " "<<i<< ColumSperator(i) << "\t";
		for (int j = 1; j <= 10; j++)
		{
		
			cout << i * j << "\t";
		}
		cout << endl;
	}
}
int main()
{
	PrintMultiplicationTable();
}