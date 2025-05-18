#include <iostream>
using namespace std;
void PrintWordsFromAAA_ZZZ()
{
    string word = "";
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int x = 65; x <= 90; x++)
            {
                
                word = word + char(i);
                word = word + char(j);
                word = word + char(x);
                cout <<word<<endl;
                word = "";
            }
        }
    }
}
int main()
{
    PrintWordsFromAAA_ZZZ();
}

