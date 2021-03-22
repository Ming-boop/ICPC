#include <iostream>

using namespace std;

int main()
{
    int year;
    cin >> year;
    cout << (!(year % 400) || (!(year % 4) && year % 100) ? 1 : 0) << endl;
    return 0;
}
