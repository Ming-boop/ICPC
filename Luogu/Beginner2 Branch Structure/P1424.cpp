#include <iostream>
#define ll long long

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    int days = n / 7 * 5;
    int remain = n % 7;
    if (remain)
    {
        if (remain + x == 7 || x == 7)
        {
            days += remain - 1;
        }
        else if (remain + x > 7)
        {
            days += remain - 2;
        }
        else
        {
            days += remain;
        }
    }
    cout << 250 * days;
    return 0;
}
