#include <iostream>
#include <string>
using namespace std;

string ReadName()
{
    string Text;
    cout << "Please Enter Text" << endl;
    getline(cin,Text);
    return Text;
}
string EncryptText(string Text,short EncryptionKey)
{  
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}
string DecryptionText(string Text, short EncryptionKey)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}
int main()
{
    short EncryptionKey = 2;
    
    string Text = ReadName();
    string TextAfterEncryption = EncryptText(Text, EncryptionKey);
    string TextAfterDecryption = DecryptionText(TextAfterEncryption, EncryptionKey);
    cout << "\nText before Encryption :" << Text << endl;
    cout << "\nText after Encryption :" << TextAfterEncryption << endl;
    cout << "\nText after Decryption :" << TextAfterDecryption << endl;
}

