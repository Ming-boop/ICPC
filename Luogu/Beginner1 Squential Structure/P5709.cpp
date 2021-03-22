#include <iostream>

using namespace std;

int main()
{
    int m, t, s;
    cin >> m >> t >> s;
    if (!t || m * t <= s)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (m * t - s) / t << endl;
    }
    return 0;
}