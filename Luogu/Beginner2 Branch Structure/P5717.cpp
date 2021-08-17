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
    if (a + b <= c)
    {
        cout << "Not triangle" << endl;
    }
    else if (a * a + b * b > c * c)
    {
        cout << "Acute triangle" << endl;
    }
    else if (a * a + b * b == c * c)
    {
        cout << "Right triangle" << endl;
    }
    else if (a * a + b * b < c * c)
    {
        cout << "Obtuse triangle" << endl;
    }
    if (a + b > c && a == b)
    {
        cout << "Isosceles triangle" << endl;
    }
    if (a == b && a == c)
    {
        cout << "Equilateral triangle" << endl;
    }
    return 0;
}
