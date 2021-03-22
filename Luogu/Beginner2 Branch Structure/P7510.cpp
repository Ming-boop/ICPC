#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    cout << (!(x % 2) && (x > 4 && x <= 12) ? 1 : 0);
    cout << " " << (!(x % 2) || (x > 4 && x <= 12) ? 1 : 0);
    cout << " " << (!(x % 2) ^ (x > 4 && x <= 12) ? 1 : 0);
    cout << " " << (x % 2 && !(x > 4 && x <= 12) ? 1 : 0) << endl;
    return 0;
}
