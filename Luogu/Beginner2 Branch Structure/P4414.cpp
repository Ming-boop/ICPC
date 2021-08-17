#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b)
    {
        swap(a, b);
    }
    if (a > c)
    {
        swap(a, c);
    }
    if (b > c)
    {
        swap(b, c);
    }
    const int cir = 3;
    char order;
    for (int i = 0; i < cir; i++)
    {
        cin >> order;
        if (i)
        {
            cout << " ";
        }
        switch (order)
        {
        case 'A':
            cout << a;
            break;
        case 'B':
            cout << b;
            break;
        case 'C':
            cout << c;
            break;
        default:
            break;
        }
    }
    cout << endl;
    return 0;
}
