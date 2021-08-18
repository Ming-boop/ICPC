#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char num[10];
    cin >> num;
    int len = strlen(num) - 1;
    if (len == 1 && num[0] == '-' && num[1] == '0')
    {
        cout << "0";
    }
    if (num[0] == '-' && num[1] != '0')
    {
        cout << "-";
    }
    while (len > 0 && num[len] == '0')
    {
        len--;
    }
    for (int i = len; i >= 0; i--)
    {
        if (num[i] != '-')
        {
            cout << num[i];
        }
    }
    cout << endl;
    return 0;
}
