#include <iostream>
#include <string>

using namespace std;

int main()
{
    string isbn;
    cin >> isbn;
    int checksum = 0, digit = 1;
    for (int i = 0; i < 12; i++)
    {
        if (isbn[i] == '-')
        {
            continue;
        }
        checksum = (checksum + digit++ * (isbn[i] - '0')) % 11;
    }
    if (isbn[12] - '0' == checksum || (checksum == 10 && isbn[12] == 'X'))
    {
        cout << "Right" << endl;
    }
    else
    {
        if (checksum < 10)
        {
            isbn[12] = checksum + '0';
        }
        else
        {
            isbn[12] = 'X';
        }
        cout << isbn << endl;
    }
    return 0;
}
