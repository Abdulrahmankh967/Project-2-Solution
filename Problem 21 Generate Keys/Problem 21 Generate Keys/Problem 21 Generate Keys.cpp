#include <iostream>
#include <cstdlib>
#include <my_library.hpp>
using namespace std;
enum enRandom { SpecialChar = 1, SmallLetter = 2, CapitalLetter = 3, Digit = 4 };
//My Solution
void GenKey(int Num)
{
	string Key;
	string GenerateKey;
	for (int i = 1; i <= Num; i++)
	{
		GenerateKey = "                                 ";
		for (int j = 1; j <= 4; j++)
		{
		Key = "    ";
			for (int x = 0; x < 4; x++)
			{
				Key[x]= char(MyLib::RandomNumber(65,90));
			}
			if (j == 1)
				GenerateKey = Key + char(45);
			else
			{
				if (j < 4)
					GenerateKey = GenerateKey + Key + char(45);
				else
					GenerateKey = GenerateKey + Key;
			}
		}
		cout <<"Key["<<i<<"]:" <<GenerateKey<< endl;
	}
}
string GenerateWord(enRandom CharType, short length)
{
	string Word;
	for (int i = 1; i <= length; i++)
	{
		Word +=MyLib::GetRandomChar(CharType);
    }
	return Word;
}
string GenerateKey()
{
	string Key="";
	Key = GenerateWord(enRandom::CapitalLetter,4) + "-";
	Key += GenerateWord(enRandom::CapitalLetter, 4) + "-";
	Key += GenerateWord(enRandom::CapitalLetter, 4) + "-";
	Key += GenerateWord(enRandom::CapitalLetter, 4);
	return Key;
}
void GenerateKeys(short NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout<<"Key["<<i<<"]:"<<GenerateKey()<<endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	GenerateKeys(MyLib::ReadNumber("Please Enter Number Of Keys"));
}

