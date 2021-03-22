#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    const double pi = 3.141593;
    int T;
    cin >> T;
    if (T == 1)
    {
        cout << "I love Luogu!";
    }
    else if (T == 2)
    {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    }
    else if (T == 3)
    {
        cout << 14 / 4 << endl
             << 14 / 4 * 4 << endl
             << 14 % 4 << endl;
    }
    else if (T == 4)
    {
        cout << setprecision(6) << 500.0 / 3 << endl;
    }
    else if (T == 5)
    {
        cout << (220 + 260) / (12 + 20) << endl;
    }
    else if (T == 6)
    {
        cout << sqrt(6 * 6 + 9 * 9) << endl;
    }
    else if (T == 7)
    {
        cout << 100 + 10 << endl
             << 100 + 10 - 20 << endl
             << 0 << endl;
    }
    else if (T == 8)
    {
        cout << 2 * 5 * pi << endl
             << pi * 5 * 5 << endl
             << 4 * pi / 3 * 5 * 5 * 5 << endl;
    }
    else if (T == 9)
    {
        cout << 2 * (1 + 2 * (1 + 2 * (1 + 1))) << endl;
    }
    else if (T == 10)
    {
        cout << 9 << endl;
    }
    else if (T == 11)
    {
        cout << 100.0 / 3 << endl;
    }
    else if (T == 12)
    {
        cout << (int)('M' - 'A') + 1 << endl
             << (char)(18 + 'A' - 1) << endl;
    }
    else if (T == 13)
    {
        cout << (int)(pow(4 * pi / 3 * (4 * 4 * 4 + 10 * 10 * 10), 1.0 / 3)) << endl;
    }
    else if (T == 14)
    {
        cout << 50 << endl;
    }
    return 0;
}