#include <iostream>
using namespace std;

string ReadPassword()
{
    string Pass;
	cout << "Please Enter Password" << endl;
	cin >> Pass;
	return Pass;
}
bool PrintWordsFromAAA_ZZZ(string Word)
{
    
    string word = "";
    int T = 1;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int x = 65; x <= 90; x++)
            {

                word = word + char(i);
                word = word + char(j);
                word = word + char(x);
                cout << "Trial[" << T << "]" << word << endl;
                if (Word == word)
                {
                    cout << "\nPassword is:"<< word << endl;
                    cout << "Found after " << T << " Trail(s)" << endl;
                    return true;
                }//this code can be login system//
                T++;
                word = "";
            }
        }
    }
}

int main()
{
    PrintWordsFromAAA_ZZZ(ReadPassword());
}

