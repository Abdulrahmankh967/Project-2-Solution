#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//My Solution
void RrandomNumber()
{
	for (int i = 1; i <= 3; i++)
	{
	
		 cout<<rand()%10<<endl;
	}
}
int RandomNumber(int from, int to)
{
	int RandNum;
	RandNum = rand() % (to-from+1) + from;
	return RandNum;
}
int main()
{
	srand((unsigned)time(NULL));
	cout << RandomNumber(5, 10)<<endl;
	cout << RandomNumber(5, 10) << endl;
	cout << RandomNumber(5, 10) << endl;


}

