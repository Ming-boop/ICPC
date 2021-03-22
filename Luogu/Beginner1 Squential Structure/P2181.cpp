#include <iostream>
typedef unsigned long long ull;

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << (ull)n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 << endl;
    return 0;
}