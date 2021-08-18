#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int hour = 7, minute = 50;
    int s;
    double v;
    cin >> s >> v;
    int time = ceil(s / v);
    hour -= time / 60;
    minute -= time % 60;
    if (minute < 0)
    {
        minute += 60;
        hour--;
    }
    if (hour < 0)
    {
        hour += 24;
    }
    if (hour < 10)
    {
        cout << "0";
    }
    cout << hour << ":";
    if (minute < 10)
    {
        cout << "0";
    }
    cout << minute << endl;
    return 0;
}
