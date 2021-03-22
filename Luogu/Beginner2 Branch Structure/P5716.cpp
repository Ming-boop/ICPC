#include <iostream>

using namespace std;

int main()
{
    int year, month;
    cin >> year >> month;
    switch (month)
    {
    case 1:
        cout << "31" << endl;
        break;
    case 2:
        cout << (!(year % 400) || (!(year % 4) && year % 100) ? "29" : "28") << endl;
        break;
    case 3:
        cout << "31" << endl;
        break;
    case 4:
        cout << "30" << endl;
        break;
    case 5:
        cout << "31" << endl;
        break;
    case 6:
        cout << "30" << endl;
        break;
    case 7:
        cout << "31" << endl;
        break;
    case 8:
        cout << "31" << endl;
        break;
    case 9:
        cout << "30" << endl;
        break;
    case 10:
        cout << "31" << endl;
        break;
    case 11:
        cout << "30" << endl;
        break;
    case 12:
        cout << "31" << endl;
        break;
    default:
        break;
    }
}
