#include <conio.h>
#include <iostream>

using namespace std;

void encrypt(string s, int k, int length)
{
    for (int i = 0; i < length; i++)
    {
        char ch = ((s[i] - 'a' + k) % 26) + 'a';
        s[i] = ch;
    }
    cout << s;
}

void decrypt(string s, int k, int length)
{
    for (int i = 0; i < length; i++)
    {
        // 'k' = 107-97 = 10-3 = 7%26 = 7+97 = 104 i.e. 'h'
        char ch = ((s[i] - 'a' - k) % 26) + 'a';
        s[i] = ch;
    }
    cout << s;
}

int main()
{
    string str;
    int key;
    cout << "Input string: " << endl;
    getline(cin, str); // Read the entire line including spaces

    cout << "Enter the shift key: ";
    cin >> key; // Letting the user to provide the shift key

    int len = str.size();

    // Remove spaces
    string result;
    for (char ch : str)
    {
        if (ch != ' ')
        {
            result += ch;
        }
    }

    cout << "Press 1 --> for Encrypt" << endl;
    cout << "Press 2 --> for Decrypt" << endl;

    int d;
    cin >> d;
    switch (d)
    {
    case 1:
        encrypt(result, key, len);
        break;

    case 2:
        decrypt(result, key, len);
        break;

    default:
        cout << "Your input is invalid!";
        break;
    }

    return 0;
}