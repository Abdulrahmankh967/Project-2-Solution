#include <iostream>
using namespace std;

enum enPrimeNotPrime{Prime=1,NotPrime=2};

int ReadNumber(string message)
{
	int N;
	cout << message << endl;
	cin >> N;
	return N;
}
enPrimeNotPrime CheckNumber(int N)
{
    
	for (int i = 2; i <= N/2; i++)
	{
		if (N % i == 0)
			return enPrimeNotPrime::NotPrime;

		
	}
		return enPrimeNotPrime::Prime;
}
void PrintPrimeFrom1toN(int N)
{
	cout << "Prime Number From 1 to " << N << " is\n";
	for (int i = 1; i <= N; i++)
	{
		if (CheckNumber(i)==enPrimeNotPrime::Prime)
			cout << i << endl;
	}
}
int main()
{
	PrintPrimeFrom1toN(ReadNumber("Please Enter a Number"));
}

