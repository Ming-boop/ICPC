#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = 60 * (c - a) + d - b;
    cout << t / 60 << " " << t % 60 << endl;
    return 0;
}