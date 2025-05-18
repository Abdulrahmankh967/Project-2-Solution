#include <iostream>
#include <cstdlib>
#include <my_library.hpp>
using namespace std;
enum enRandom { SpecialChar = 1, SmallLetter = 2,CapitalLetter = 3,Digit=4 };
char GetRandomChar(enRandom Rand)
{
	switch (Rand)
	{
	case enRandom::SpecialChar:
		return (MyLib::RandomNumber(33, 47));
	case enRandom::SmallLetter:
		return (MyLib::RandomNumber(97, 122));
	case enRandom::CapitalLetter:
		return (MyLib::RandomNumber(65, 90));
	case enRandom::Digit:
		return (MyLib::RandomNumber(48,57));
	}
}
int main()
{
	srand((unsigned)time(NULL));
  /*cout << char(MyLib::RandomNumber(65, 90)) << endl;
  cout << char(MyLib::RandomNumber(97, 122))<<endl;
  cout << char(MyLib::RandomNumber(33, 47)) << endl;
  cout << (MyLib::RandomNumber(1, 10)) << endl;*/
	
	cout << GetRandomChar(enRandom::CapitalLetter) << endl;
	cout << GetRandomChar(enRandom::SmallLetter) << endl;
	cout << GetRandomChar(enRandom::SpecialChar) << endl;
	cout << GetRandomChar(enRandom::Digit) << endl;


  

}
