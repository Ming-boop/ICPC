#include <iostream>

using namespace std;

int main()
{
    int k, n;
    double s = 0;
    cin >> k;
    for (n = 1; s <= k; n++)
    {
        s += 1.0 / n;
    }
    cout << n - 1 << endl;
    return 0;
}
