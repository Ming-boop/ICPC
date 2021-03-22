#include <iomanip>
#include <iostream>

using namespace std;

const double price_below = 0.4463, price_between = 0.4663, price_above = 0.5663;

int main()
{
    int electricity;
    cin >> electricity;
    if (electricity < 151)
    {
        cout << fixed << setprecision(1) << electricity * price_below << endl;
    }
    else if (electricity < 401)
    {
        cout << fixed << setprecision(1) << price_between * (electricity - 150) + price_below * 150 << endl;
    }
    else
    {
        cout << fixed << setprecision(1) << price_above * (electricity - 400) + price_between * (400 - 150) + price_below * 150 << endl;
    }
    return 0;
}
