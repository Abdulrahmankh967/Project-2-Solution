#include <iostream>
#include "my_library.hpp"
using namespace std;

bool CheckPalindrome(int Num)
{
	return Num == MyLib::ReverseDigits(Num);
}
void PrintPalindrome(int Num)
{
	if (CheckPalindrome(Num))
		cout << "Yes,Its Palindrome Number" << endl;
	else
	cout << "No,Its Not Palindrome Number" << endl;

}
int main()
{
	PrintPalindrome(MyLib::ReadNumber("Please Enter a Number"));
}

